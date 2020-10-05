#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
ll ans=0,out=0;//ans为最终的数列中逆序对的数量，out为对原数列中每个值进行异或的值

void dfs(vector<vector<ll>>now,int deep)//二维数组now记录数列在当前层数被分割成了几个部分,deep为当前算的是二进制第几位
{
    ll temp=1ll<<deep;
    ll cas0,cas1,sum0=0,sum1=0;//sum0和sum1分别记录当前二进制deep位上，以该位为0的值作为逆序对的右侧（也就是out在此位取0）的逆序对数量
    //和以该位为1的值作为逆序对的右侧(也就是out在此位取1，使得该位的所有数0和1转化）的逆序对数量
    vector<vector<ll>>next;//下一次dfs的二维数组
    vector<ll>next0,next1;//当前分割部分的vector中，二进制deep位为0和1的数字分别放入两个vector
    for(int i=0;i<now.size();i++)
    {
        cas0=cas1=0;
        for(int j=0;j<now[i].size();j++)
        {
            if(now[i][j]&temp) {sum1+=cas0;cas1++;next1.push_back(now[i][j]);}
            else {sum0+=cas1;cas0++;next0.push_back(now[i][j]);}
        }
        if(next0.size()) {next.push_back(next0);next0.clear();}//避免不需要的递归和空间浪费，如果next0和next1不为0才压入下次dfs的数组里
        if(next1.size()) {next.push_back(next1);next1.clear();}
    }
    if(sum0>sum1) {ans+=sum1;out+=temp;}//如果以该位为0的值作为逆序对右侧的逆序对数量大于以该位为1的值作为逆序对的右侧，代表out需要在该位取1
    else ans+=sum0;
    if(deep==0) return;
    dfs(next,deep-1);
}

int32_t main()
{
    IOS;
    cin>>n;
    vector<vector<ll>>num(1);
    num[0].resize(n);
    for(auto &x:num[0]) cin>>x;
    dfs(num,30);//dfs30层即可，1e9的最高位也不过2的30次
    cout<<ans<<' '<<out<<endl;
}
