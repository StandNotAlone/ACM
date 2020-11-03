#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

int a[maxn];

struct Node
{
    int l,r,data;//线段树维护的是，l-r区间的值，各自在数列中出现的最右侧位置下标的最小值是多少
}node[maxn<<2];

void build(int now,int l,int r)
{
    node[now].l=l;node[now].r=r;node[now].data=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
}

void change(int now,int tar,int x)//更改值为tar的数字的最右侧位置下标为x
{
    if(node[now].l==node[now].r)
    {
        node[now].data=x;
        return;
    }
    int mid=(node[now].l+node[now].r)>>1;
    if(mid>=tar) change(now<<1,tar,x);
    else change(now<<1|1,tar,x);
    node[now].data=min(node[now<<1].data,node[now<<1|1].data);
}

int ask(int now,int tar)//询问下标从1开始的区间中，其维护的最右侧下标最小值不超过tar的最右侧下标为多少，实际上就是在求针对tar到主函数for循环参数i这个区间的数列，其对应的MEX值
{
    if(node[now].l==node[now].r) return node[now].l;
    if(node[now<<1].data<tar) return ask(now<<1,tar);
    else return ask(now<<1|1,tar);
}

bool flag[maxn];//记录数列a各个子序列能得到那些MEX值
int pre[maxn];//pre[i]记录数值i上次出现的下标位置，用于ask函数的区间范围确定

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    build(1,1,maxn);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(pre[a[i]]+1<i) flag[ask(1,pre[a[i]]+1)]=1;//注意这里和下一个for循环的特判区间是否为空，如果不特判的话会导致算出一个MEX值1，使得结果出错
        pre[a[i]]=i;
        change(1,a[i],i);
    }
    for(int i=1;i<maxn;i++) if(pre[i]&&pre[i]<n) flag[ask(1,pre[i]+1)]=1;//对于每个数字，其最后一次出现到数列末尾的这个区间未在上述for循环中询问
    flag[ask(1,1)]=1;//注意上述情况是不包括询问整个数列的
    for(int i=1;;i++) if(!flag[i]) {cout<<i<<endl;break;}
}
