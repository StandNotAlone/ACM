#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int treenum[maxn],Min[maxn];//treenum[i]代表以i为根的子树有几个节点，Min[i]代表以i为根的子树中
int l,r,prel,prer;//树上两个指针指示当前路径的两端
vector<int>dir[maxn];//存图
bool f[maxn];
ll ans[maxn];
ll sum;

void dfs(int now,int pre){
    treenum[now]=1;
    Min[now]=now;
    for(int i=0;i<dir[now].size();i++){
        if(dir[now][i]==pre) continue;
        dfs(dir[now][i],now);
        treenum[now]+=treenum[dir[now][i]];
        Min[now]=min(Min[now],Min[dir[now][i]]);
    }
}

void work(int tar){
    if(l==tar||r==tar){
        ll x,y;
        if(treenum[prel]>treenum[l]) x=treenum[l];
        else x=n-treenum[prel];
        if(treenum[prer]>treenum[r]) y=treenum[r];
        else y=n-treenum[prer];
        ans[tar]=sum-x*y;
        sum=x*y;
        return;
    }
    for(int i=0;i<dir[l].size();i++){
        int to=dir[l][i];
        if(to==prel) continue;
        if(Min[to]==tar){
            f[to]=1;
            if(l==r) prer=to;
            prel=l;
            l=to;
            work(tar);
            return;
        }
    }
    for(int i=0;i<dir[r].size();i++){
        int to=dir[r][i];
        if(to==prer) continue;
        if(Min[to]==tar){
            f[to]=1;
            prer=r;
            r=to;
            work(tar);
            return;
        }
    }
}

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<n;i++){
            int a,b;cin>>a>>b;
            dir[a].push_back(b);
            dir[b].push_back(a);
        }
        for(int i=0;i<n;i++) {Min[i]=INF;ans[i]=0;f[i]=0;}
        ans[n]=0;f[n]=0;
        dfs(0,-1);
        l=r=0;prel=prer=-1;
        sum=(ll)n*(n-1)/2;
        for(int i=0;i<dir[0].size();i++){
            ll temp=treenum[dir[0][i]];
            ans[0]+=temp*(temp-1)/2;
            sum-=temp*(temp-1)/2;
        }
        for(int i=1;i<=n;i++){
            if(f[i]) continue;
            work(i);
            if(l!=i&&r!=i) {ans[i]=sum;break;}
        }
        for(int i=0;i<=n;i++) cout<<ans[i]<<' ';
        cout<<endl;
        for(int i=0;i<n;i++) dir[i].clear();
    }
}
