#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=5e5+7;
const double eps=1e-6;
const int mod=1e9+7;

struct Node{
    int l,r;
    int Max,Maxl,Maxr,sum;
}tree[maxn<<2];
int num[maxn];

void pushup(Node &a,Node &b,Node &c){
    c.Max=max(max(a.Max,b.Max),a.Maxr+b.Maxl);
    c.sum=a.sum+b.sum;
    c.Maxr=max(b.Maxr,a.Maxr+b.sum);
    c.Maxl=max(a.Maxl,a.sum+b.Maxl);
}

void build(int l,int r,int tar){
    tree[tar].l=l;
    tree[tar].r=r;
    if(l==r){
        tree[tar].sum=tree[tar].Max=tree[tar].Maxl=tree[tar].Maxr=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,tar<<1);
    build(mid+1,r,tar<<1|1);
    pushup(tree[tar<<1],tree[tar<<1|1],tree[tar]);
}

Node ask(int l,int r,int tar){
    if(l<=tree[tar].l&&r>=tree[tar].r) return tree[tar];
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(l<=mid&&r>mid){
        Node temp1=ask(l,r,tar<<1);
        Node temp2=ask(l,r,tar<<1|1);
        Node ret;
        pushup(temp1,temp2,ret);
        return ret;
    }
    else{
        if(l<=mid) return ask(l,r,tar<<1);
        else return ask(l,r,tar<<1|1);
    }
}

void change(int x,int y,int tar){
    if(tree[tar].l==tree[tar].r){
        tree[tar].sum=tree[tar].Max=tree[tar].Maxl=tree[tar].Maxr=y;
        return;
    }
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(x<=mid) change(x,y,tar<<1);
    else change(x,y,tar<<1|1);
    pushup(tree[tar<<1],tree[tar<<1|1],tree[tar]);
}

int n,m;

int main(){
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,n,1);
    while(m--){
        int k,x,y;cin>>k>>x>>y;
        if(k==1){
            if(x>y) swap(x,y);
            Node temp=ask(x,y,1);
            cout<<temp.Max<<endl;
        }
        else change(x,y,1);
    }
}
