#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int dp[32007];
int N,m,v[70],p[70],q[70];
vector<int>dir[70];
int tot,tempv[4],tempp[4];

int main(){
    scanf("%d%d",&N,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&v[i],&p[i],&q[i]);
        if(q[i]) dir[q[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        if(!q[i]){
            tempv[0]=v[i];tempp[0]=v[i]*p[i];
            if(dir[i].size()==0) tot=1;
            if(dir[i].size()==1){
                tot=2;
                tempv[1]=v[dir[i][0]]+tempv[0];tempp[1]=v[dir[i][0]]*p[dir[i][0]]+tempp[0];
            }
            if(dir[i].size()==2){
                tot=4;
                tempv[1]=v[dir[i][0]]+tempv[0];tempp[1]=v[dir[i][0]]*p[dir[i][0]]+tempp[0];
                tempv[2]=v[dir[i][1]]+tempv[0];tempp[2]=v[dir[i][1]]*p[dir[i][1]]+tempp[0];
                tempv[3]=v[dir[i][0]]+v[dir[i][1]]+tempv[0];
                tempp[3]=v[dir[i][0]]*p[dir[i][0]]+v[dir[i][1]]*p[dir[i][1]]+tempp[0];
            }
            for(int j=N;j>=0;j--)
                for(int k=0;k<tot;k++)
                    if(j>=tempv[k]&&dp[j]<dp[j-tempv[k]]+tempp[k])
                        dp[j]=dp[j-tempv[k]]+tempp[k];
        }
    }
    printf("%d\n",dp[N]);
}
