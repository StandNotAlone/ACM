#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> change(ll x)//把整数x按照十进制转换成vector数组返回
{
    vector<int> s;
    stack<int>S;
    while(x) {S.push(x%10);x/=10;}
    while(S.size()) {s.push_back(S.top());S.pop();}
    return s;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        vector<int> sn=change(n);
        int tar=-1,sum=0;//tar为满足下标tar前面所有十进制位上的值累加满足小于s的最大下标位置
        //sum为当前的十进制位数值累加和
        for(int i=0;i<sn.size();i++)//寻找tar的位置
        {
            sum+=sn[i];
            if(sum>s) break;
            if(sum<s) tar=i;
        }
        if(sum<=s) cout<<0<<endl;//如果整个数列的十进制位上数字累加不超过s，那么不需要进行任何操作
        else
        {
            ll ans=0;//ans为我们最后构造的满足条件的最小结果
            if(tar==-1)//如果tar=-1，代表第一位上的数字就已经超出s限制了，直接构造10000...00，0的个数为原数字十进制长度
            {
                ans=1;
                for(int i=0;i<sn.size();i++) ans*=10;
            }
            else
            {
                for(int i=0;i<=tar;i++)//下标tar前的数字保持原本数值
                    ans=ans*10+sn[i];
                ans++;//tar位置后面的部分通过不断增加的操作，累加后进位1到下标tar位置
                for(int i=tar+1;i<sn.size();i++)//后面的十进制位上全部置零
                    ans*=10;
            }
            cout<<ans-n<<endl;
        }
    }
}
