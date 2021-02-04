#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define int long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int n,m;
int num[maxn];

struct Node
{
    int l,r,data,tar;
};

Node st[4*maxn];

void build(int l,int r,int loca)
{
    st[loca].l=l;
    st[loca].r=r;
    if(l==r) {st[loca].data=num[l];st[loca].tar=l;}
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,loca<<1);
        build(mid+1,r,loca<<1|1);
        if(st[loca<<1].data>st[loca<<1|1].data)
        {
            st[loca].data=st[loca<<1].data;
            st[loca].tar=st[loca<<1].tar;
        }
        else
        {
            st[loca].data=st[loca<<1|1].data;
            st[loca].tar=st[loca<<1|1].tar;
        }
    }
}

pair<int,int> ask(int l,int r,int loca)
{
    if(st[loca].l>=l&&st[loca].r<=r) return {st[loca].data,st[loca].tar};
    int mid=(st[loca].l+st[loca].r)>>1;
    pair<int,int>temp={-1,-1};
    if(l<=mid) temp=ask(l,r,loca<<1);
    if(r>mid)
    {
        pair<int,int>temp1=ask(l,r,loca<<1|1);
        if(temp1.first>temp.first) temp=temp1;
    }
    return temp;
}

struct ANS
{
    int grade;
    ll cas;
};
vector<ANS>ans;
vector<int>keneng;

int search(int l,int r,int tar)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(keneng[mid]<tar) l=mid+1;
        else r=mid;
    }
    return l;
}

void dfs(int l,int r)
{
    if(r<l) return;
    if(l==r) ans.push_back({num[keneng[l]],1});
    else
    {
        pair<int,int>temp=ask(keneng[l],keneng[r],1);
        int x=search(l,r,temp.second);
        if(keneng[x]==temp.second)
        {
            ll xx=((ll)x-l)*(r-x)*2;
            ans.push_back({temp.first,xx+(r-l+1)*2-1});
            dfs(l,x-1);
            dfs(x+1,r);
        }
        else
        {
            ans.push_back({temp.first,((ll)x-l)*(r-x+1)*2});
            dfs(l,x-1);
            dfs(x,r);
        }
    }
}

bool cmp1(ANS a,ANS b)
{
    return a.grade<b.grade;
}

void work()
{
    int k;scanf("%lld",&k);
    ll K=k*k;
    for(int i=1;i<=k;i++)
    {
        int x;scanf("%lld",&x);
        keneng.push_back(x);
    }
    sort(keneng.begin(),keneng.end());

    dfs(0,k-1);

    sort(ans.begin(),ans.end(),cmp1);
    for(int i=0;i<ans.size();i++)
    {
        printf("%lld ",ans[i].grade);
        ll temp=gcd(ans[i].cas,K);
        printf("%lld/%lld\n",ans[i].cas/temp,K/temp);
    }
    ans.clear();
    keneng.clear();
}

int32_t main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
    build(1,n,1);
    scanf("%lld",&m);
    while(m--) work();
}

//5
//1 3 5 2 4
//1
//5 5 4 3 2 1
