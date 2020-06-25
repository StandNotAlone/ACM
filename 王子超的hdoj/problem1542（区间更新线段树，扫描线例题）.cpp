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
 
ll n;
 
vector<double>originx,originy;
 
ll findx(double x)
{
    return lower_bound(originx.begin(),originx.end(),x)-originx.begin();
}
 
ll findy(double y)
{
    return lower_bound(originy.begin(),originy.end(),y)-originy.begin();
}
 
struct Node
{
    ll l,r,ope;
    double data;
};
 
Node st[4*maxn];
 
void build(ll l,ll r,ll loca)
{
    st[loca].l=l;
    st[loca].r=r;
    st[loca].data=0;
    st[loca].ope=0;
    if(l==r) return ;
    else
    {
        ll mid=(l+r)>>1;
        build(l,mid,loca<<1);
        build(mid+1,r,loca<<1|1);
    }
}
 
 
void change(ll l,ll r,ll loca,ll ope)
{
    if(st[loca].l>=l&&st[loca].r<=r)
    {
        if(ope==1)
        {
            st[loca].ope++;
            st[loca].data=originy[st[loca].r]-originy[st[loca].l-1];
        }
        else
        {
            st[loca].ope--;
            if(st[loca].ope==0)
            {
                if(st[loca].l==st[loca].r)
                {
                    st[loca].data=0;
                }
                else st[loca].data=st[loca<<1].data+st[loca<<1|1].data;
            }
        }
        return ;
//        st[loca].ope+=ope;
//        if(st[loca].ope) st[loca].data=originy[st[loca].r]-originy[st[loca].l-1];
//        else
//        {
//            if(st[loca].l==st[loca].r) st[loca].data=0;
//            else st[loca].data=st[loca<<1].data+st[loca<<1|1].data;
//        }
//        return ;
    }
    ll mid=(st[loca].l+st[loca].r)>>1;
    if(l<=mid) change(l,r,loca<<1,ope);
    if(r>mid) change(l,r,loca<<1|1,ope);
    if(st[loca].ope==0) st[loca].data=st[loca<<1].data+st[loca<<1|1].data;
}
 
struct Len
{
    double x,y1,y2;
    ll ope;
};
 
 
 
vector<Len>len;
 
bool cmp(Len L1,Len L2)
{
    return L1.x<L2.x;
}
 
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);cout.tie(0);使用之后不要混用cin和scanf printf
    ll Case=0;
    while(scanf("%lld",&n))
    {
        if(!n) break;
        originx.clear();
        originy.clear();
        len.clear();
        for(ll i=0;i<n;i++)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            originx.push_back(x1);
            originx.push_back(x2);
            originy.push_back(y1);
            originy.push_back(y2);
            len.push_back({x1,y1,y2,1});
            len.push_back({x2,y1,y2,-1});
        }
        sort(originx.begin(),originx.end());
        sort(originy.begin(),originy.end());
        originx.erase(unique(originx.begin(),originx.end()),originx.end());
        originy.erase(unique(originy.begin(),originy.end()),originy.end());
        sort(len.begin(),len.end(),cmp);
        ll lengt=originy.size();
        build(1,lengt-1,1);
        double ans=0;
        change(findy(len[0].y1)+1,findy(len[0].y2),1,len[0].ope);
        ll i=1;
        while(i<2*n)
        {
            ans+=(len[i].x-len[i-1].x)*st[1].data;
            change(findy(len[i].y1)+1,findy(len[i].y2),1,len[i].ope);
            i++;
        }
        printf("Test case #%lld\n",++Case);
        printf("Total explored area: %.2lf\n\n",ans);
    }
 
}