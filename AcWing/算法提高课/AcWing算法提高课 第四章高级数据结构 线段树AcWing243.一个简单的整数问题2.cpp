#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
ll num[maxn];

struct Tree{
    int l,r;
    ll sum;
    ll lazy;
}tree[maxn<<2];

void build(int l,int r,int tar){
    tree[tar].l=l;tree[tar].r=r;
    tree[tar].lazy=0;
    if(l==r){
        tree[tar].sum=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,tar<<1);
    build(mid+1,r,tar<<1|1);
    tree[tar].sum=tree[tar<<1].sum+tree[tar<<1|1].sum;
}

void pushdown(Tree &fa,Tree &son1,Tree &son2){
    if(fa.lazy){
        son1.lazy+=fa.lazy;
        son2.lazy+=fa.lazy;
        son1.sum+=fa.lazy*(son1.r-son1.l+1);
        son2.sum+=fa.lazy*(son2.r-son2.l+1);
        fa.lazy=0;
    }
}

void change(int l,int r,ll y,int tar){
    if(tree[tar].l>=l&&tree[tar].r<=r){
        tree[tar].sum+=y*(tree[tar].r-tree[tar].l+1);
        tree[tar].lazy+=y;
        return;
    }
    pushdown(tree[tar],tree[tar<<1],tree[tar<<1|1]);
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(r<=mid) change(l,r,y,tar<<1);
    else if(l>mid) change(l,r,y,tar<<1|1);
    else {change(l,r,y,tar<<1);change(l,r,y,tar<<1|1);}
    tree[tar].sum=tree[tar<<1].sum+tree[tar<<1|1].sum;
}

ll ask(int l,int r,int tar){
    if(tree[tar].l>=l&&tree[tar].r<=r) return tree[tar].sum;
    pushdown(tree[tar],tree[tar<<1],tree[tar<<1|1]);
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(r<=mid) return ask(l,r,tar<<1);
    else if(l>mid) return ask(l,r,tar<<1|1);
    else return ask(l,r,tar<<1)+ask(l,r,tar<<1|1);
}

int main(){
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,n,1);
    while(m--){
        char ope;cin>>ope;
        if(ope=='Q'){
            int l,r;cin>>l>>r;
            cout<<ask(0,r,1)-ask(0,l-1,1)<<endl;
        }
        else{
            int l,r;
            ll d;
            cin>>l>>r>>d;
            change(l,r,d,1);
        }
    }
}
