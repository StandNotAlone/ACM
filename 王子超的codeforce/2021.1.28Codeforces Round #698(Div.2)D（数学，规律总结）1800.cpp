#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;

ll num[maxn];
int n;
ll k;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            if(num[i]==k) flag=1;//如果输入的值已经是k了就没必要进行后续部分
        }
        if(!flag)
        {
            vector<ll>cas;
            for(int i=1;i<n;i++) cas.push_back(abs(num[i]-num[i-1]));//相邻两个数之间的差值
            for(int i=1;i<cas.size();i++) cas[0]=gcd(cas[0],cas[i]);//求取差值的最大公约数
            //即利用所给的这些数作差，任意组合后能得到的最小一块的值是多少
            for(int i=0;i<n;i++)
            {
                ll temp=k-num[i];//枚举除了差值之外，多余的那一个数是哪一个
                if(temp%cas[0]==0) flag=1;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
