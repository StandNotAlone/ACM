#include<bits/stdc++.h>
#include <unordered_map>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int a[maxn],b[maxn],e[maxn];
int tot;
unordered_map<int,int>M;
int fa[maxn*2];

int get(int x){
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tot=0;
        M.clear();
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d%d",&x,&y,&e[i]);
            if(M.count(x)==0) M[x]=tot++;
            if(M.count(y)==0) M[y]=tot++;
            a[i]=M[x];b[i]=M[y];
        }
        for(int i=0;i<tot;i++) fa[i]=i;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(e[i]){
                int l=get(a[i]),r=get(b[i]);
                if(l!=r) fa[l]=r;
            }
        }
        for(int i=0;i<n;i++){
            if(!e[i]&&get(a[i])==get(b[i])) {flag=0;break;}
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
