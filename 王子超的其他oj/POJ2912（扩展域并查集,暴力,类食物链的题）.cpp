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

void read(ll &a,ll &b,int &cp)
{
    getchar();
    char s[30];
    scanf("%s",s);
    bool flag=0;
    a=0;b=0;
    ll len=strlen(s);
    for(ll i=0;i<len;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            if(flag) b=b*10+s[i]-'0';
            else a=a*10+s[i]-'0';
        }
        else
        {
            if(s[i]=='>') cp=1;
            if(s[i]=='=') cp=0;
            if(s[i]=='<') cp=-1;
            flag=1;
        }
    }
}

struct Node
{
    ll a,b;
    int cp;
};

ll n,m;

vector<ll>fa;

void init()
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x)
{
    return x==fa[x]?x:fa[x]=get(fa[x]);
}

void merge(ll x,ll y)
{
    fa[get(x)]=get(y);
}

vector<Node>node;

void judge(ll &ans,ll &sum,ll &tar,ll now)
{
    fa.clear();
    fa.resize(3*n);//fa[i]为自身位置,fa[i+n]为自己吃的,fa[i+2*n]为吃自己的
    init();
    for(ll i=0;i<m;i++)
    {
        if(node[i].a==now||node[i].b==now) continue;
        else
        {
            if(node[i].cp==1)
            {
                if(get(node[i].a)==get(node[i].b)||get(node[i].a)==get(node[i].b+n))
                {
                    tar=max(tar,i);
                    return;
                }
                else
                {
                    merge(node[i].a+n,node[i].b);
                    merge(node[i].a+2*n,node[i].b+n);
                    merge(node[i].a,node[i].b+2*n);
                }
            }
            else if(node[i].cp==0)
            {
                if(get(node[i].a)==get(node[i].b+n)||get(node[i].a+n)==get(node[i].b))
                {
                    tar=max(tar,i);
                    return;
                }
                else
                {
                    merge(node[i].a,node[i].b);
                    merge(node[i].a+n,node[i].b+n);
                    merge(node[i].a+2*n,node[i].b+2*n);
                }
            }
            else
            {
                if(get(node[i].a)==get(node[i].b)||get(node[i].a+n)==get(node[i].b))
                {
                    tar=max(tar,i);
                    return;
                }
                else
                {
                    merge(node[i].a,node[i].b+n);
                    merge(node[i].a+n,node[i].b+2*n);
                    merge(node[i].a+2*n,node[i].b);
                }
            }
        }
    }
    sum++;
    ans=now;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(scanf("%lld%lld",&n,&m)!=EOF)     //此题输入数据范围很小，并且给了5s的时间，因此可以用一些较暴力的方案
    {
        node.clear();
        node.resize(m);
//        if(n==1)
//        {
//            printf("Player 0 can be determined to be the judge after 0 lines\n");
//            continue;
//        }
        ll ans=-1,sum=0,tar=-1;             //sum记录有几个可能的judge,tar保存的是其他不满足的情况中最大的行数
        for(ll i=0;i<m;i++)
        {
            read(node[i].a,node[i].b,node[i].cp);
        }
        for(ll i=0;i<n;i++)             //枚举假设某一个结点为我们寻找的judge去判断是否满足
        {
            judge(ans,sum,tar,i);
        }
        if(sum==0) printf("Impossible\n");
        else if(sum==1) printf("Player %lld can be determined to be the judge after %lld lines\n",ans,tar+1);
        else printf("Can not determine\n");
    }
}
