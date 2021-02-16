#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=37;
const double eps=1e-8;

int n;
int pre[maxn],now[maxn];
int a[maxn][maxn];

int gauss()
{
    int r,c;
    for(r=c=0;c<n;c++)
    {
        int tar=r;
        for(int i=r+1;i<=n;i++)
            if(a[i][c]) tar=i;
        if(!a[tar][c]) continue;
        for(int i=c;i<=n;i++) swap(a[tar][i],a[r][i]);
        for(int i=r+1;i<=n;i++)
            if(a[i][c])
                for(int j=n;j>=c;j--)
                    a[i][j]=a[i][j]^a[r][j];
        r++;
    }
    if(r<n)
    {
        for(int i=r;i<=n;i++)
            if(a[i][n]) return -1;
        return n-r;
    }
    for(int i=n;i>=0;i--)
        for(int j=i+1;j<=n;j++)
            if(a[i][j]&&a[j][j]) a[i][n]=a[i][n]^a[j][n];
    return 0;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) cin>>pre[i];
        for(int i=0;i<n;i++) cin>>now[i];
        for(int i=0;i<n;i++) a[i][i]=1,a[i][n]=pre[i]^now[i];
        int x,y;
        while(1)
        {
            cin>>x>>y;
            if(x==0&&y==0) break;
            a[y-1][x-1]=1;
        }
        int ans=gauss();
        if(ans==-1) cout<<"Oh,it's impossible~!!"<<endl;
        else cout<<(1<<ans)<<endl;
    }
}
