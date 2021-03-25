#include<bits/stdc++.h>
using namespace std;
const int maxn=107;

int N,V,v[maxn],w[maxn],f;
int dp[maxn][maxn];
vector<int>dir[maxn];
int root=-1;

void dfs(int now){
    int temp[2][maxn];
    bool flag=0;
    memset(temp,0,sizeof(temp));
    for(int i=0;i<dir[now].size();i++){
        dfs(dir[now][i]);
        for(int i=0;i<=V;i++) temp[!flag][i]=0;
        for(int j=V-v[now];j>=0;j--){
            for(int k=0;k<=j;k++){
                temp[!flag][j]=max(temp[!flag][j],temp[flag][k]+dp[dir[now][i]][j-k]);
            }
        }
        flag=!flag;
    }
    for(int i=V;i>=v[now];i--) dp[now][i]=temp[flag][i-v[now]]+w[now];
}

int main(){
    scanf("%d%d",&N,&V);
    for(int i=1;i<=N;i++){
        cin>>v[i]>>w[i]>>f;
        if(f==-1) root=i;
        else dir[f].push_back(i);
    }
    dfs(root);
    cout<<dp[root][V]<<endl;
}
