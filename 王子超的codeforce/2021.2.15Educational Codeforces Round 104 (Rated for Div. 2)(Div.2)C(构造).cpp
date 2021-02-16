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
        if(n%2==1)//奇数球队的时候直接平均分配胜负场即可
        {
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if((i+j)%2==1) cout<<1<<' ';
                    else cout<<-1<<' ';
        }
        else//偶数的时候每支球队安排一场平局，其余同上构造
        {
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(j==i+1&&i%2==1) cout<<0<<' ';
                    else if((i+j)%2==1) cout<<1<<' ';
                    else cout<<-1<<' ';
        }
        cout<<endl;
    }
}
