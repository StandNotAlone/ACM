#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+7;

int fa[maxn];
int c[maxn],d[maxn];
int n,m,w;

void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}

int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}

void merge(int x,int y){
    d[get(y)]+=d[get(x)];
    c[get(y)]+=c[get(x)];
    fa[get(x)]=get(y);
}

int dp[maxn];

int main(){
    scanf("%d%d%d",&n,&m,&w);
    init();
    for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
    for(int i=0;i<m;i++){
        int a,b;scanf("%d%d",&a,&b);
        if(get(a)!=get(b)) merge(a,b);
    }
    for(int i=1;i<=n;i++){
        if(get(i)==i){
            for(int j=w;j>=c[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]]+d[i]);
        }
    }
    printf("%d\n",dp[w]);
}
