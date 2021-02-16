#include<bits/stdc++.h>
#define ll long long
#define INF 2000000000//定义一个足够大的值作为无穷大
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=15e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int ans=INF;
int n[4];
int need[4][maxn];//保存每种菜要多少花费
int dp[4][maxn];//dp[i][j]代表从第一轮开始选，选到i+1轮使用第j种的最少花费

struct Node
{
    int l,r;
    int num;//保存区间最小值
};
Node st[maxn<<2];

void build(int l,int r,int loca,int cas)
{
    st[loca].l=l;st[loca].r=r;
    if(l==r) {st[loca].num=dp[cas][l];return;}
    int mid=(l+r)>>1;
    build(l,mid,loca<<1,cas);
    build(mid+1,r,loca<<1|1,cas);
    st[loca].num=min(st[loca<<1].num,st[loca<<1|1].num);
}

void change(int tar,int loca,int x)//单点修改位置tar的值为x
{
    if(st[loca].l==st[loca].r)
    {
        st[loca].num=x;
        return;
    }
    int mid=(st[loca].l+st[loca].r)>>1;
    if(tar<=mid) change(tar,loca<<1,x);
    else change(tar,loca<<1|1,x);
    st[loca].num=min(st[loca<<1].num,st[loca<<1|1].num);
}

bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

vector<pair<int,int>>buyao;//保存哪些组合是不允许的
vector<pair<int,int>>daichuli;//保存上一种情况哪些被删除掉了，当前要把这些值加回来

int main()
{
    IOS
    for(int i=0;i<4;i++) cin>>n[i];
    for(int i=0;i<4;i++)
        for(int j=1;j<=n[i];j++)
            cin>>need[i][j];
    for(int j=1;j<=n[0];j++) dp[0][j]=need[0][j];
    for(int i=1;i<4;i++)
    {
        build(1,n[i-1],1,i-1);//根据上次的dp结果重新建树
        int m;cin>>m;
        buyao.clear();
        buyao.resize(m);
        for(int j=0;j<m;j++) cin>>buyao[j].first>>buyao[j].second;
        sort(buyao.begin(),buyao.end(),cmp);//按照当前选择的种类的序号从小到大排序

        daichuli.clear();
        int now=0;
        for(int j=1;j<=n[i];j++)
        {
            for(int k=0;k<daichuli.size();k++)
                change(daichuli[k].first,1,dp[i-1][daichuli[k].first]);//把上轮被删掉了的加回来
            daichuli.clear();
            while(now<m&&buyao[now].second==j)//和当前的第j种无法组合的全部删掉，并且用daichuli记录，在下次循环中加回来
            {
                change(buyao[now].first,1,INF);
                daichuli.push_back(buyao[now]);
                now++;
            }
            dp[i][j]=st[1].num;//直接取当前剩余总区间的最小值
            if(dp[i][j]!=INF) dp[i][j]+=need[i][j];//如果等于INF无穷大的话，就代表不存在能与j组合的情况，不再做处理
        }
    }

    for(int j=1;j<=n[3];j++)
        if(dp[3][j]<ans) ans=dp[3][j];
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}
