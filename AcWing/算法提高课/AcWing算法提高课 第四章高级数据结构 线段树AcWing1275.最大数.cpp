#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int m,p,tot=0,a=0;

struct Node{
    int l,r,Max;
}tree[maxn<<2];

void build(int l,int r,int now){
    tree[now].l=l;
    tree[now].r=r;
    tree[now].Max=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,now<<1);
    build(mid+1,r,now<<1|1);
}

void change(int tar,int x,int now){
    if(tree[now].l==tree[now].r){
        tree[now].Max=x;
        return;
    }
    int mid=(tree[now].l+tree[now].r)>>1;
    if(tar<=mid) change(tar,x,now<<1);
    else change(tar,x,now<<1|1);
    tree[now].Max=max(tree[now<<1].Max,tree[now<<1|1].Max);
}

int ask(int l,int r,int now){
    if(l<=tree[now].l&&r>=tree[now].r) return tree[now].Max;
    int ret=0;
    int mid=(tree[now].l+tree[now].r)>>1;
    if(l<=mid) ret=max(ret,ask(l,r,now<<1));
    if(r>mid) ret=max(ret,ask(l,r,now<<1|1));
    return ret;
}

int main(){
    IOS
    cin>>m>>p;
    build(1,200000,1);
    while(m--){
        char ope;
        int x;
        cin>>ope>>x;
        if(ope=='A') change(++tot,(x+a)%p,1);
        else cout<<(a=ask(tot-x+1,tot,1))<<endl;
    }
}
