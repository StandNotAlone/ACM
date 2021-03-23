#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=16e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int dp[2][maxn];
bool f;
int n,m;

struct Node{
    int l,p,s;
}node[107];

int cal(int i,int j){
    return dp[f][j]-node[i].p*j;
}

bool cmp(Node a,Node b){return a.s<b.s;}

int main(){
    IOS
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>node[i].l>>node[i].p>>node[i].s;
    sort(node,node+m,cmp);
    for(int i=0;i<m;i++){
        deque<int>Q;
        for(int j=max(0,node[i].s-node[i].l);j<node[i].s;j++){
            while(Q.size()&&cal(i,Q[Q.size()-1])<=cal(i,j)) Q.pop_back();
            Q.push_back(j);
        }
        for(int j=1;j<=n;j++){
            dp[!f][j]=max(dp[f][j],dp[!f][j-1]);
            while(Q.size()&&j-Q[0]>node[i].l) Q.pop_front();
            if(j>=node[i].s){
                if(Q.size()&&cal(i,Q[0])+j*node[i].p>dp[!f][j])
                    dp[!f][j]=cal(i,Q[0])+j*node[i].p;
            }
        }
        f=!f;
    }
    cout<<dp[f][n]<<endl;
}
