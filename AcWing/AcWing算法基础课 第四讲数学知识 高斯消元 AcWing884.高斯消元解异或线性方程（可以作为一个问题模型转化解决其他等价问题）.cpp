#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const double eps=1e-5;
const int maxn=1e2+7;

int n;
int a[maxn][maxn];

int gauss()//a[n+1][n+1]的增广矩阵，方程数量小于n的时候直接无解
//方程数量等于n时最后一行全部补0即可
{
    int r,c;
    for(r=c=0;c<n;c++)
    {
        int tar=r;
        for(int i=r+1;i<=n;i++)//找绝对值最大的行并替换到当前第一行
            if(a[i][c]) tar=i;
        if(!a[tar][c]) continue;
        for(int i=c;i<=n;i++) swap(a[tar][i],a[r][i]);
        for(int i=r+1;i<=n;i++)//利用当前第一行将当前第一列下方全部消为0
            if(a[i][c])
                for(int j=n;j>=c;j--)
                    a[i][j]=a[i][j]^a[r][j];
        r++;
    }
    if(r<n)
    {
        for(int i=r;i<=n;i++)
            if(a[i][n]) return 2;//无解
        return 1;//有无穷组解
    }
    for(int i=n;i>=0;i--)
        for(int j=i+1;j<=n;j++)
            if(a[i][j]&&a[j][j]) a[i][n]=a[i][n]^a[j][n];
    return 0;//有唯一解
}

int32_t main()
{
    IOS;
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            cin>>a[i][j];
    int ans=gauss();
    if(ans==1) cout<<"Multiple sets of solutions"<<endl;
    else if(ans==2) cout<<"No solution"<<endl;
    else for(int i=0;i<n;i++) cout<<a[i][n]<<endl;
}
