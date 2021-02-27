#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>num(n);
        int cas[3]={0};
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            if(num[i]%3==0) cas[0]++;
            else if(num[i]%3==1) cas[1]++;
            else cas[2]++;
        }
        int ans=0;
        for(int i=0;i<2;i++)//循环两遍
         for(int j=0;j<3;j++)
            if(cas[j]>n/3) {ans+=cas[j]-n/3;cas[(j+1)%3]+=cas[j]-n/3;cas[j]=n/3;}
        cout<<ans<<endl;
    }
}
