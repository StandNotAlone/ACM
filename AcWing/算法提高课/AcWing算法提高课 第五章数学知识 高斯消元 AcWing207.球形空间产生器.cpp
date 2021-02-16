#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=17;
const double eps=1e-8;

int n;
double num[maxn][maxn];
double a[maxn][maxn];

int gauss()
{
    int r,c;
    for(r=c=0;c<n;c++)
    {
        int tar=r;
        for(int i=r+1;i<=n;i++)
            if(fabs(a[i][c])>fabs(a[tar][c])) tar=i;
        if(fabs(a[tar][c])<eps) continue;
        for(int i=c;i<=n;i++) swap(a[tar][i],a[r][i]);
        for(int i=n;i>=c;i--) a[r][i]/=a[r][c];
        for(int i=r+1;i<=n;i++)
            if(fabs(a[i][c])>eps)
                for(int j=n;j>=c;j--)
                    a[i][j]-=a[r][j]*a[i][c];
        r++;
    }
    if(r<n)
    {
        for(int i=r;i<=n;i++)
            if(fabs(a[i][n])>eps) return 2;
        return 1;
    }
    for(int i=n;i>=0;i--)
        for(int j=i+1;j<=n;j++)
            a[i][n]-=a[i][j]*a[j][n];
    return 0;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<n;j++)
            cin>>num[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=2*num[i+1][j]-2*num[i][j];
            a[i][n]+=num[i+1][j]*num[i+1][j]-num[i][j]*num[i][j];
        }
    }
    cout<<fixed<<setprecision(3);
    gauss();
    for(int i=0;i<n;i++) cout<<a[i][n]<<' ';
}
