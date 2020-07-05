#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[maxn][maxn];
int cas[maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        printf("Case %d: ",CASE);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=INF;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&cas[i]);
            dp[i][i]=1;
        }
        for(int len=2;len<=n;len++)
        {
            for(int l=1;l+len-1<=n;l++)
            {
                int r=l+len-1;
                for(int mid=l;mid<r;mid++)
                {
                    int temp=dp[l][mid]+dp[mid+1][r];
                    if(cas[mid]==cas[r]) temp--;
                    dp[l][r]=min(dp[l][r],temp);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
}


