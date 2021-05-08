#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;

vector<double>Y;

int findy(double now){
    return (int)(lower_bound(Y.begin(),Y.end(),now)-Y.begin());
}

struct Node{
    double x,y[2];
    int flag;
}node[maxn<<1];

bool cmp(Node a,Node b){
    return a.x<b.x;
}

struct Tree{
    int l,r;
    int lazy;
    double data;
}tree[maxn<<2];

void build(int l,int r,int tar){
    tree[tar].l=l;
    tree[tar].r=r;
    tree[tar].lazy=0;
    tree[tar].data=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,tar<<1);
    build(mid+1,r,tar<<1|1);
}

void push_up(int tar){
    if(tree[tar].lazy) tree[tar].data=Y[tree[tar].r]-Y[tree[tar].l-1];
    else {
        if(tree[tar].l==tree[tar].r) tree[tar].data=0;
        else tree[tar].data=tree[tar<<1].data+tree[tar<<1|1].data;
    }
}

void change(int l,int r,int tar,int flag){
    if(tree[tar].l>=l&&tree[tar].r<=r){
        tree[tar].lazy+=flag;
        push_up(tar);
        return;
    }
    int mid=(tree[tar].l+tree[tar].r)>>1;
    if(l<=mid) change(l,r,tar<<1,flag);
    if(r>mid) change(l,r,tar<<1|1,flag);
    push_up(tar);
}

int main(){
    int CAS=0;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        Y.clear();
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&node[i<<1].x,&node[i<<1].y[0],&node[i<<1|1].x,&node[i<<1].y[1]);
            node[i<<1|1].y[0]=node[i<<1].y[0];
            node[i<<1|1].y[1]=node[i<<1].y[1];
            node[i<<1].flag=1;
            node[i<<1|1].flag=-1;
            Y.push_back(node[i<<1].y[0]);
            Y.push_back(node[i<<1].y[1]);
        }
        sort(Y.begin(),Y.end());
        sort(node,node+2*n,cmp);
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        double ans=0;
        int lim=(int)Y.size();
        build(1,lim-1,1);
        for(int i=0;i<2*n;i++){
            if(i) ans+=(node[i].x-node[i-1].x)*tree[1].data;
            int l=findy(node[i].y[0]),r=findy(node[i].y[1]);
            change(l+1,r,1,node[i].flag);
            //cout<<l<<' '<<r<<' '<<tree[1].data<<endl;
        }
        printf("Test case #%d\n",++CAS);
        printf("Total explored area: %.2lf\n\n",ans);
    }
}
