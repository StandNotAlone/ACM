#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#define ll long long
#define llINF 9223372036854775807
using namespace std;
const double eps=1e-10;

double dp[21][21];
vector<double>y[21];
int n;
double x[21];

bool check(int l,int r,double y1,double y2)
{
    bool flag=1;
    for(int i=l+1;i<r;i++)
    {
        double Y=y1+(y2-y1)*(x[i]-x[l])/(x[r]-x[l]);
        if(Y>=y[i][0]&&Y<=y[i][1]||Y>=y[i][2]&&Y<=y[i][3]);
        else flag=0;
    }
    return flag;
}

void solve()
{
    for(int i=1;i<=n+1;i++)
    {
        for(int j=0;j<y[i].size();j++)
        {
            for(int k=0;k<i;k++)
            {
                for(int l=0;l<y[k].size();l++)
                {
                    if(check(k,i,y[k][l],y[i][j]))
                    {
                        dp[i][j]=min(dp[i][j],dp[k][l]+sqrt((x[k]-x[i])*(x[k]-x[i])+(y[k][l]-y[i][j])*(y[k][l]-y[i][j])));
                    }
                }
            }
        }
    }
}

int main()
{
    y[0].push_back(5.0);x[0]=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1) break;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<4;j++)
                dp[i][j]=llINF;
        for(int i=1;i<21;i++) y[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&x[i]);
            for(int j=0;j<4;j++)
            {
                double temp;
                scanf("%lf",&temp);
                y[i].push_back(temp);
            }
        }
        y[n+1].push_back(5.0);x[n+1]=10;
        dp[0][0]=0;
        solve();
        printf("%.2lf\n",dp[n+1][0]);
    }
}