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

struct Node
{
    ll x,y;
};

vector<ll>origin;//离散化数组

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}

vector<vector<ll> >dir;     //dir[i]保存从i点出发的各条路径
vector<Node>cas;            //保存输入数据
vector<ll>pre;              //保存父节点位置以寻找根

vector<ll>fa;

void init()
{
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());
    dir.resize(origin.size());
    fa.resize(origin.size());
    pre.resize(origin.size());
    for(ll i=0;i<fa.size();i++)
    {
        fa[i]=i;
        pre[i]=i;
    }
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void famerge(ll x,ll y)
{
    fa[get(y)]=get(x);
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    Node node;
    ll CASE=1;
    while(scanf("%lld%lld",&node.x,&node.y))
    {
        if(node.x==-1&&node.y==-1) break;
        origin.clear();
        dir.clear();
        fa.clear();
        pre.clear();
        cas.clear();
        while(1)
        {
            if(!node.x&&!node.y) break;
            origin.push_back(node.x);
            origin.push_back(node.y);
            cas.push_back(node);
            scanf("%lld%lld",&node.x,&node.y);
        }
        init();
        if(cas.size()==0)	//注意特判下空树的情况
        {
            printf("Case %lld is a tree.\n",CASE++);
            continue;
        }
        bool flag=1;
        ll sum=1;
        for(ll i=0;i<cas.size();i++)
        {
            ll x=find(cas[i].x),y=find(cas[i].y);
            if(get(x)==get(y))
            {
                flag=0;
                break;
            }
            dir[x].push_back(y);
            pre[y]=x;
            famerge(x,y);
            sum++;
        }
        printf("Case %lld is ",CASE++);
        if(!flag||sum!=origin.size()) printf("not ");
        else
        {
            flag=1;
            ll root=0;
            while(pre[root]!=root) root=pre[root];
            vector<int>F(origin.size(),0);
            sum=1;
            deque<ll>Q;
            Q.push_back(root);
            F[root]=1;
            while(Q.size())
            {
                if(!flag) break;
                for(ll i=0;i<dir[Q[0]].size();i++)
                {
                    if(F[dir[Q[0]][i]])
                    {
                        flag=0;
                        break;
                    }
                    F[dir[Q[0]][i]]=1;
                    Q.push_back(dir[Q[0]][i]);
                    sum++;
                }
                Q.pop_front();
            }
            if(!flag||sum!=origin.size()) printf("not ");
        }
        printf("a tree.\n");
    }
}


