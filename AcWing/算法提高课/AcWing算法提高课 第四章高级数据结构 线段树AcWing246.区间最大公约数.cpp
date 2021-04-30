#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=5e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;

struct Tree{
    int l,r;
    ll sum,d;
}tree[maxn<<2];

ll num[maxn];

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

void pushup(Tree &ret,Tree &a,Tree &b){
    ret.sum=a.sum+b.sum;
    ret.d=gcd(a.d,b.d);
}

void build(int l,int r,int tar){
    tree[tar].l=l;tree[tar].r=r;
    if(l==r){
        tree[tar].d=tree[tar].sum=num[l]-num[l-1];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,tar<<1);
    build(mid+1,r,tar<<1|1);
    pushup(tree[tar],tree[tar<<1],tree[tar<<1|1]);
}

void change(int x,ll y,int tar){
    if(tree[tar].l==tree[tar].r){
        tree[tar].sum=tree[tar].d=tree[tar].d+y;
        return;
    }
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(x<=mid) change(x,y,tar<<1);
    else change(x,y,tar<<1|1);
    pushup(tree[tar],tree[tar<<1],tree[tar<<1|1]);
}

Tree ask(int l,int r,int tar){
    if(tree[tar].l>=l&&tree[tar].r<=r) return tree[tar];
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(r<=mid) return ask(l,r,tar<<1);
    else if(l>mid) return ask(l,r,tar<<1|1);
    else{
        Tree temp1,temp2=ask(l,r,tar<<1),temp3=ask(l,r,tar<<1|1);
        pushup(temp1,temp2,temp3);
        return temp1;
    }
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
            Tree temp1=ask(1,l,1);
            Tree temp2={0,0,0,0};
            if(l<r) temp2=ask(l+1,r,1);
            printf("%lld\n",abs(gcd(temp1.sum,temp2.d)));
        }
        else{
            int l,r;
            ll d;
            cin>>l>>r>>d;
            change(l,d,1);
            if(r<n) change(r+1,-d,1);
        }
    }
}
