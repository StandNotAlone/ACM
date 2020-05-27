#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

//这道题中不管是天使还是恶魔阵营的，由于天使必定说真话，恶魔必定说假话，所以我们总能从一句问话中得到正确的信息
//询问a:"b是不是天使",如果回答是yes，那么有a和b同为天使，或者a和b同为恶魔两种情况
//如果回答是no，那么有a为天使b为恶魔，或者a为恶魔，b为天使两种情况

//我们只关注a和b是否在同一个阵营的话，会发现yes就是ab同阵营，no就是ab在对立阵营，由此建立并查集，可以将所有人分为各个集合
//每个集合中分为两个阵营，但是我们不知道他们分别具体属于哪个阵营

//由此我们引入背包dp，即对于阵营集合num[i]来说，和根节点相同阵营的人属于天使还是属于恶魔，就相当于01背包
//dp[i][j]代表用前i个集合，组成j个天使有几种方案
//如果和当前集合根节点相同阵营的人属于天使则增加相同阵营的人的人数到当前天使人数上，如果和当前集合根节点不同阵营的人属于天使，也对应的将这些人数加到当前天使人数上
//最后检测所有集合都被使用后，dp[][p1]的方案数是否为1，如果有多重方案则是不确定的情况，同样输出no

ll n,p1,p2;

vector<ll>fa;
vector<ll>dis;

void fainit()
{
    for(ll i=0;i<fa.size();i++)
    {
        fa[i]=i;
        dis[i]=0;
    }
}

ll get(ll x)
{
    if(x==fa[x]) return x;
    ll root=get(fa[x]);
    dis[x]^=dis[fa[x]];
    return fa[x]=root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(scanf("%lld%lld%lld",&n,&p1,&p2),n||p1||p2)
    {
        fa.clear();
        dis.clear();
        ll sum=p1+p2;
        fa.resize(sum+1);
        dis.resize(sum+1);
        fainit();
        char s[4];
        ll a,b;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld%lld %s",&a,&b,s);
            ll x=get(a),y=get(b);
            if(x!=y)            //注意这一块的合并操作...wa了几发才发现这里写错了
            {
                fa[x]=y;
                dis[x]=dis[a]^dis[b];
                if(s[0]=='n') dis[x]^=1;
            }
        }
        vector<ll>num;
        for(ll i=1;i<=sum;i++)
            if(i==get(i)) num.push_back(i); //每一个num中的值都代表一个集合的代表元素
        vector<vector<ll> >field(num.size()*2); //下标+num代表与该集合代表元素所在阵营不同的元素个数，不加下标代表相同的元素个数
        for(ll i=0;i<num.size();i++)
        {
            for(ll j=1;j<=sum;j++)
            {
                if(get(j)==num[i])
                {
                    if(dis[j]) field[i+num.size()].push_back(j);
                    else field[i].push_back(j);
                }
            }
        }
        vector<vector<ll> >dp(num.size()),root(num.size());     //背包dp,root存储路径
        for(ll i=0;i<num.size();i++)
        {
            dp[i].resize(p1+1,0);
            root[i].resize(p1+1,0);
            for(ll j=0;j<=p1;j++)
            {
                dp[i][j]=0;
                root[i][j]=0;
            }
        }
        if(field[0].size()<=p1)
        {
            dp[0][field[0].size()]+=1;
            root[0][field[0].size()]=1;
        }
        if(field[num.size()].size()<=p1)
        {
            dp[0][field[num.size()].size()]+=1;
            root[0][field[num.size()].size()]=-1;
        }
        for(ll i=1;i<num.size();i++)
        {
            for(ll j=0;j<=p1;j++)
            {
                if(field[i].size()<=j&&dp[i-1][j-(ll)field[i].size()])
                {
                    dp[i][j]+=dp[i-1][j-(ll)field[i].size()];
                    root[i][j]=1;
                }
                if(field[i+num.size()].size()<=j&&dp[i-1][j-(ll)field[i+num.size()].size()])
                {
                    dp[i][j]+=dp[i-1][j-(ll)field[i+num.size()].size()];
                    root[i][j]=-1;
                }
            }
        }
        if(dp[(ll)num.size()-1][p1]!=1) printf("no\n");
        else
        {
            vector<ll>ans;
            ll nowi=(ll)num.size()-1,nowj=p1;
            while(nowi>=0)
            {
                if(root[nowi][nowj]==1)
                {
                    for(ll i=0;i<field[nowi].size();i++) ans.push_back(field[nowi][i]);
                    nowj-=(ll)field[nowi].size();
                }
                else
                {
                    for(ll i=0;i<field[nowi+num.size()].size();i++) ans.push_back(field[nowi+num.size()][i]);
                    nowj-=(ll)field[nowi+num.size()].size();
                }
                nowi--;
            }
            sort(ans.begin(),ans.end());
            for(ll i=0;i<ans.size();i++) printf("%lld\n",ans[i]);
            printf("end\n");
            ans.clear();
        }
        num.clear();
        dp.clear();
        field.clear();
    }
}


