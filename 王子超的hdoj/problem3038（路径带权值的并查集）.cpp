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

ll n,m;

//���鼯����
vector<ll>fa;
vector<ll>dis;//dis[i]��¼i�����Լ����ڼ��ϸ��ڵ��֮�����ֵĺ�
ll ans=0;

void fainit()
{
    for(ll i=0;i<fa.size();i++) fa[i]=i;
}

ll get(ll x)
{
    if(x==fa[x]) return x;
    ll root=get(fa[x]);
    dis[x]+=dis[fa[x]];
    return fa[x]=root;
}

void famerge(ll x,ll y,ll len)
{
    ll rootx=get(x),rooty=get(y);
    fa[rootx]=rooty;
    dis[rootx]=dis[y]-dis[x]+len;   //ע���Ƶ�������������ô���ģ��������±��С�ĵ����Ϊ�����򣬿������۷��֣���rootx>rooty��ʱ�򣬵õ��ľ���ǡ���Ƿ���Ҳ����ȡ�෴����ֵ
}                                   //�����²�������ʱ����Ȼ������õ�ʽ�ģ��˴���Ҫ�����뿴��һ������������һ���з��������

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        ans=0;
        fa.resize(n+1);
        fainit();
        dis.resize(n+1);
        for(ll i=0;i<=n;i++) dis[i]=0;
        while(m--)
        {
            ll a,b,s;
            scanf("%lld%lld%lld",&a,&b,&s);
            a--;
            if(get(a)==get(b))
            {
                if(dis[a]-dis[b]!=s) ans++;//ע���Ƶ�������������ô����
            }
            else famerge(a,b,s);
        }
        printf("%lld\n",ans);
    }
}


