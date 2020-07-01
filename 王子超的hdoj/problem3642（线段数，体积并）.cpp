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
const ll maxn=2e3+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,atot,ans,minz,maxz;

vector<ll>origin;

ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}

struct Area
{
    ll x,y1,y2,z1,z2,ope;
};

bool cmp(Area A,Area B)
{
    return A.x<B.x;
}

Area area[maxn];

struct Node
{
    ll l,r,sum1,sum2,sum3,flag;
};

Node st[maxn*4];

void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].sum1=st[loca].sum2=st[loca].sum3=st[loca].flag=0;
    if(l==r) return;
    ll mid=(l+r)>>1;
    build(l,mid,loca<<1);
    build(mid+1,r,loca<<1|1);
}

void pushup(ll loca)
{
    if(st[loca].flag>2)
    {
        st[loca].sum1=st[loca].sum2=st[loca].sum3=origin[st[loca].r]-origin[st[loca].l-1];
    }
    else if(st[loca].flag==2)
    {
        st[loca].sum1=st[loca].sum2=origin[st[loca].r]-origin[st[loca].l-1];
        if(st[loca].l==st[loca].r) st[loca].sum3=0;
        else st[loca].sum3=st[loca<<1].sum1+st[loca<<1|1].sum1;
    }
    else if(st[loca].flag==1)
    {
        st[loca].sum1=origin[st[loca].r]-origin[st[loca].l-1];
        if(st[loca].l==st[loca].r) st[loca].sum2=st[loca].sum3=0;
        else
        {
            st[loca].sum2=st[loca<<1].sum1+st[loca<<1|1].sum1;
            st[loca].sum3=st[loca<<1].sum2+st[loca<<1|1].sum2;
        }
    }
    else
    {
        if(st[loca].l==st[loca].r) st[loca].sum1=st[loca].sum2=st[loca].sum3=0;
        else
        {
            st[loca].sum1=st[loca<<1].sum1+st[loca<<1|1].sum1;
            st[loca].sum2=st[loca<<1].sum2+st[loca<<1|1].sum2;
            st[loca].sum3=st[loca<<1].sum3+st[loca<<1|1].sum3;
        }
    }
}

void change(ll l,ll r,ll loca,ll ope)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        st[loca].flag+=ope;
        pushup(loca);
        return;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1,ope);
    if(r>mid) change(l,r,loca<<1|1,ope);
    pushup(loca);
}

void work()
{
    build(1,origin.size()-1,1);
    for(ll z=minz;z<=maxz;z++)
    {
        vector<Area>now;
        for(ll i=0;i<atot;i++)
        {
            if(z>=area[i].z1&&z<=area[i].z2) now.push_back(area[i]);
        }
        change(find(now[0].y1)+1,find(now[0].y2),1,now[0].ope);
        for(ll i=1;i<now.size();i++)
        {
            if(now[i].x!=now[i-1].x)
            {
                ans+=(now[i].x-now[i-1].x)*st[1].sum3;
            }
            change(find(now[i].y1)+1,find(now[i].y2),1,now[i].ope);
        }
        now.clear();
    }
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    ll t;
    scanf("%lld",&t);
    for(ll cas=1;cas<=t;cas++)
    {
        minz=llINF;
        maxz=-llINF;
        ans=0;atot=0;
        scanf("%lld",&n);
        origin.clear();
        for(ll i=0;i<n;i++)
        {
            ll x1,y1,z1,x2,y2,z2;
            scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&z1,&x2,&y2,&z2);
            area[atot].x=x1;area[atot+1].x=x2;
            area[atot].y1=area[atot+1].y1=y1;
            area[atot].y2=area[atot+1].y2=y2;
            area[atot].z1=area[atot+1].z1=z1;
            area[atot].z2=area[atot+1].z2=z2-1;
            area[atot].ope=1;
            area[atot+1].ope=-1;
            atot+=2;
            origin.push_back(y1);
            origin.push_back(y2);
            minz=min(z1,minz);
            maxz=max(z2-1,maxz);
        }
        sort(area,area+atot,cmp);
        sort(origin.begin(),origin.end());
        origin.erase(unique(origin.begin(),origin.end()),origin.end());
        work();
        printf("Case %lld: %lld\n",cas,ans);
    }
}


