#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;



int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll>ans;//ans为我们最后输出的构造数列
        ans.push_back(x);ans.push_back(y);
        ll dis=0;//dis为y-x的值在满足(y-x)/dis<=n-1条件下的最小因子,也是排序后的数列中相邻两个数字的差值
        //因为总共只有n个数字，其中的间隔最多只有n-1个。我们尽可能让dis更小，使得最后数列中的最大值尽可能小
        for(ll i=n-1;i;i--)//计算y-x的值在满足(y-x)/dis<=n-1条件下的最小因子
            if((y-x)%i==0) {dis=(y-x)/i;break;}
        for(ll i=x+dis;i<y;i+=dis)//先把值大小在x和y之间的数字放进最终数列中
            ans.push_back(i);
        for(ll i=x-dis;i>0;i-=dis)//当数列长度不够的时候，先考虑比x小的数字
            //注意从x开始往下减，因为我们要保证最后的数列是个等差数列
            //先考虑比x的部分，不会影响最大值，此时的最大值仍然是y
        {
            if(ans.size()==n) break;//长度足够则跳出循环
            ans.push_back(i);
        }
        for(ll i=y+dis;;i+=dis)//长度仍然不够，只能增大数列的最大值，从y+dis开始
            //依次增加，并推入结果数列中
        {
            if(ans.size()==n) break;
            ans.push_back(i);
        }
        for(ll i=0;i<ans.size();i++)
        {
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
}
