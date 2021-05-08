#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
ll mod;

int n,m;
ll num[maxn];

struct Tree{
    int l,r;
    ll lazy1,lazy2;
    ll data;
}tree[maxn<<2];

void build(int l,int r,int tar){
    tree[tar].l=l;tree[tar].r=r;
    tree[tar].lazy1=1;
    tree[tar].lazy2=0;
    if(l==r){
        tree[tar].data=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,tar<<1);
    build(mid+1,r,tar<<1|1);
    tree[tar].data=(tree[tar<<1].data+tree[tar<<1|1].data)%mod;
}

void push_down(int tar){
    tree[tar<<1].data=tree[tar<<1].data*tree[tar].lazy1%mod;
    tree[tar<<1|1].data=tree[tar<<1|1].data*tree[tar].lazy1%mod;
    tree[tar<<1].lazy1=tree[tar<<1].lazy1*tree[tar].lazy1%mod;
    tree[tar<<1|1].lazy1=tree[tar<<1|1].lazy1*tree[tar].lazy1%mod;
    tree[tar<<1].lazy2=tree[tar<<1].lazy2*tree[tar].lazy1%mod;
    tree[tar<<1|1].lazy2=tree[tar<<1|1].lazy2*tree[tar].lazy1%mod;

    tree[tar<<1].data=(tree[tar<<1].data+tree[tar].lazy2*(tree[tar<<1].r-tree[tar<<1].l+1))%mod;
    tree[tar<<1|1].data=(tree[tar<<1|1].data+tree[tar].lazy2*(tree[tar<<1|1].r-tree[tar<<1|1].l+1))%mod;
    tree[tar<<1].lazy2=(tree[tar<<1].lazy2+tree[tar].lazy2)%mod;
    tree[tar<<1|1].lazy2=(tree[tar<<1|1].lazy2+tree[tar].lazy2)%mod;

    tree[tar].lazy2=0;
    tree[tar].lazy1=1;
}

void change(int l,int r,int tar,int flag,ll x){
    if(tree[tar].l>=l&&tree[tar].r<=r){
        if(flag){
            tree[tar].lazy1=tree[tar].lazy1*x%mod;
            tree[tar].lazy2=tree[tar].lazy2*x%mod;
            tree[tar].data=tree[tar].data*x%mod;
        }
        else{
            tree[tar].lazy2=(tree[tar].lazy2+x)%mod;
            tree[tar].data=(tree[tar].data+x*(tree[tar].r-tree[tar].l+1))%mod;
        }
        return;
    }
    push_down(tar);
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(l<=mid) change(l,r,tar<<1,flag,x);
    if(r>mid) change(l,r,tar<<1|1,flag,x);
    tree[tar].data=(tree[tar<<1].data+tree[tar<<1|1].data)%mod;
}

ll ask(int l,int r,int tar){
    if(tree[tar].l>=l&&tree[tar].r<=r) return tree[tar].data;
    int mid=(tree[tar].l+tree[tar].r)>>1;
    push_down(tar);
    ll ret=0;
    if(l<=mid) ret+=ask(l,r,tar<<1);
    if(r>mid) ret+=ask(l,r,tar<<1|1);
    return ret%mod;
}

int main(){
    IOS
    cin>>n>>mod;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,n,1);
    cin>>m;
    while(m--){
        int ope,t,g,c=0;cin>>ope>>t>>g;
        if(ope!=3) cin>>c;
        if(ope==1) change(t,g,1,1,c);
        if(ope==2) change(t,g,1,0,c);
        if(ope==3) cout<<ask(t,g,1)<<endl;
    }
}
