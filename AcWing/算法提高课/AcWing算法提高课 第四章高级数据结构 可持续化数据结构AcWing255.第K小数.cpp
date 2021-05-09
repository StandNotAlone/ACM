#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int tot=0,head[100007];//head[i]代表前i个数的数据构成的线段树
int n,m;
int num[maxn];

vector<int>origin;

int find(int x){
    return (int)(lower_bound(origin.begin(),origin.end(),x)-origin.begin())+1;
}

struct Tree{
    int lson,rson;
    int data;
}tree[maxn*2];//n最大1e5,需要开nlogn的空间，2e6不到一些

int build(int l,int r){
    //主席树维护的是origin数组中[l,r]范围内的数有几个
    int now=++tot;
    tree[now].data=0;
    if(l!=r){
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
    }
    return now;
}

int insert(int pre,int l,int r,int x){
    //第origin[x]的出现次数+1
    int now=++tot;
    tree[now]=tree[pre];//复制之前的信息
    if(l!=r){
        int mid=(l+r)>>1;
        if(x<=mid) tree[now].lson=insert(tree[now].lson,l,mid,x);
        else tree[now].rson=insert(tree[now].rson,mid+1,r,x);
    }
    tree[now].data++;
    return now;
}

int ask(int tarl,int tarr,int l,int r,int k){
    //在tarl和tarr两颗树中，区间为[l,r]，找第k大的树
    //tarr是前r个数构成的树，tarl是前l-1个数构成的树
    //两者相减的数量即为[l,r]区间内的个数
    if(l==r) return l;
    int mid=(l+r)>>1;
    int temp=tree[tree[tarr].lson].data-tree[tree[tarl].lson].data;
    //计算左边区间有几个数
    if(k<=temp) return ask(tree[tarl].lson,tree[tarr].lson,l,mid,k);
    else return ask(tree[tarl].rson,tree[tarr].rson,mid+1,r,k-temp);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        origin.push_back(num[i]);
    }
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());
    head[0]=build(1,(int)origin.size());
    for(int i=1;i<=n;i++) head[i]=insert(head[i-1],1,(int)origin.size(),find(num[i]));
    for(int i=1;i<=m;i++){
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        int tar=ask(head[l-1],head[r],1,(int)origin.size(),k)+1;
        printf("%d\n",origin[ask(head[l-1],head[r],1,(int)origin.size(),k)-1]);
    }
}
