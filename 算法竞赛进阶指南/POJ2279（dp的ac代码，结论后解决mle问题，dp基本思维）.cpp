#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll n,num[6];

int main()
{
    IOS;
    while(1)
    {
        cin>>n;
        if(!n) break;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++) cin>>num[i];
        ll dp[31][16][11][8][7];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0][0]=1;
        for(ll a=0;a<=num[1];a++)
            for(ll b=0;b<=min(a,num[2]);b++)
                for(ll c=0;c<=min(b,num[3]);c++)
                    for(ll d=0;d<=min(c,num[4]);d++)
                        for(ll e=0;e<=min(d,num[5]);e++){
                            ll temp=dp[a][b][c][d][e];
                            if(a<num[1]) dp[a+1][b][c][d][e]+=temp;
                            if(b<num[2]) dp[a][b+1][c][d][e]+=temp;
                            if(c<num[3]) dp[a][b][c+1][d][e]+=temp;
                            if(d<num[4]) dp[a][b][c][d+1][e]+=temp;
                            if(e<num[5]) dp[a][b][c][d][e+1]+=temp;
                        }
        cout<<dp[num[1]][num[2]][num[3]][num[4]][num[5]]<<endl;
    }
}


