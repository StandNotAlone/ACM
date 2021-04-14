#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e4+7;

int fa[maxn];
int n,m;

void init(){
    for(int i=1;i<=n*n;i++) fa[i]=i;
}

int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}

void merge(int x,int y){
    fa[get(x)]=get(y);
}

int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=m;i++){
        int a,b;
        char c;
        scanf("%d%d %c",&a,&b,&c);
        int now=(a-1)*n+b;
        int temp;
        if(c=='D') temp=now+n;
        else temp=now+1;
        if(get(now)==get(temp)) {printf("%d\n",i);return 0;}
        merge(now,temp);
    }
    printf("draw\n");
}
