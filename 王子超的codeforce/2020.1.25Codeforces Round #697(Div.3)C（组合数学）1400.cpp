#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;

int boy[maxn],girl[maxn];//boy[i]和girl[i]分别记录标号为i的男/女生在多少对组合中出现了
int x[maxn],y[maxn];

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int a,b,k;cin>>a>>b>>k;
        for(int i=0;i<k;i++) cin>>x[i];
        for(int i=0;i<k;i++)
        {
            cin>>y[i];
            boy[x[i]]++;
            girl[y[i]]++;
        }
        ll ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=(k-boy[x[i]]-girl[y[i]]+1);
            //总共k对组合
            //我们选择了(x[i],y[i])这一对，那么包含了x[i]的有boy[x[i]]对，包含y[i]的有girl[y[i]]对
            //其中(x[i],y[i])被重复计算了，所以包含x[i]或者y[i]的共有boy[x[i]]+girl[y[i]]-1
            //那么既不包含x[i]又不包含y[i]的就是k-(boy[x[i]]+girl[y[i]]-1)对了
        }
        cout<<ans/2<<endl;//注意到是C(1,2)的取法，最后要除以2
        for(int i=1;i<=a;i++) boy[i]=0;
        for(int i=1;i<=b;i++) girl[i]=0;
    }
}
