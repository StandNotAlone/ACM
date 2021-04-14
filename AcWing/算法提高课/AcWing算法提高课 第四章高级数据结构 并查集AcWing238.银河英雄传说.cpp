#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=3e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int dis[maxn];
int fa[maxn];
int siz[maxn];

void init(){
    for(int i=1;i<maxn;i++) {fa[i]=i;siz[i]=1;}
}

int  get(int x){
    if(x!=fa[x]){
        int temp=fa[x];
        fa[x]=get(fa[x]);
        dis[x]+=dis[temp];
    }
    return fa[x];
}

void merge(int x,int y){
    x=get(x);
    y=get(y);
    fa[x]=y;
    dis[x]=siz[y];
    siz[y]+=siz[x];
}


int main(){
    int t;scanf("%d",&t);
    init();
    while(t--){
        getchar();
        char c;
        int a,b;
        scanf("%c%d%d",&c,&a,&b);
        if(c=='M') merge(a,b);
        else{
            if(get(a)==get(b)) printf("%d\n",abs(dis[a]-dis[b])-1);
            else printf("-1\n");
        }
    }
}
