#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=5e5+10;

//题意为给定一个长度为n（最大2e5）的数列，以及m（最大1e5）条指令
//每条指令包含k,l,r三个数字
//k=1的指令为输出在数列下标l和r之间的最大连续子序列和
//k=2的指令为将数列下标为l的数替换成数r

//如果采用dp求取最大连续子序列和的话，单次查询复杂度为O（n)，总的时间复杂度O（nm)达到1e10肯定是不可行的
//利用线段树来求取最大连续子序列和，单次查询复杂度为O（logn），总复杂度O（mlogn）达到要求

//实际上线段树的实现就用到了dp的思想，毕竟dp本来就不是一种固定的算法
//线段树第一题
//线段树的每个节点记录6个数据:l,r,sum,lmax,rmax,max
//l和r代表这个节点记录的是哪个区间的数据，sum为整个区间的累加和，lmax为取最左侧数的最大连续子序列和，rmax为取最右侧数的最大连续子序列和
//max为该区间的最大连续子序列和

//关键在于从子节点将状态转移到父节点的状态转移方程是怎么样的
//转移方程见build函数末尾部分
//另外此题的一个难点在于ask函数要如何来实现，很多地方理解都还不够透彻，等下次重写.

ll A[maxn];

struct SegmentTree
{
    ll l,r;
    ll sum,lmax,rmax,max;
}ST[4*maxn];

void buildST(ll l,ll r,ll loca)
{
    ST[loca].l=l;
    ST[loca].r=r;
    if(l==r)
    {
        ST[loca].sum=A[l];
        ST[loca].max=A[l];
        ST[loca].lmax=A[l];
        ST[loca].rmax=A[l];
        return;
    }
    ll mid=l+((r-l)>>1);
    buildST(l,mid,2*loca);
    buildST(mid+1,r,2*loca+1);
    ST[loca].max=max(ST[loca*2].max,max(ST[loca*2+1].max,ST[loca*2].rmax+ST[loca*2+1].lmax));
    ST[loca].sum=ST[loca*2].sum+ST[loca*2+1].sum;
    ST[loca].lmax=max(ST[loca*2].lmax,ST[loca*2].sum+ST[loca*2+1].lmax);
    ST[loca].rmax=max(ST[loca*2+1].rmax,ST[loca*2].rmax+ST[loca*2+1].sum);
}

void changeST(ll x,ll loca)
{
    if(ST[loca].l==ST[loca].r)
    {
        ST[loca].sum=A[x];
        ST[loca].max=A[x];
        ST[loca].lmax=A[x];
        ST[loca].rmax=A[x];
        return;
    }
    ll mid=ST[loca].l+((ST[loca].r-ST[loca].l)>>1);
    if(mid>=x) changeST(x,loca*2);
    else changeST(x,loca*2+1);
    ST[loca].max=max(ST[loca*2].max,max(ST[loca*2+1].max,ST[loca*2].rmax+ST[loca*2+1].lmax));
    ST[loca].sum=ST[loca*2].sum+ST[loca*2+1].sum;
    ST[loca].lmax=max(ST[loca*2].lmax,ST[loca*2].sum+ST[loca*2+1].lmax);
    ST[loca].rmax=max(ST[loca*2+1].rmax,ST[loca*2].rmax+ST[loca*2+1].sum);
}

SegmentTree askST(ll l,ll r,ll loca)
{
    if(l<=ST[loca].l&&r>=ST[loca].r) return ST[loca];
    ll mid=ST[loca].l+((ST[loca].r-ST[loca].l)>>1);
    if(mid<l) return askST(l,r,loca*2+1);
    if(mid>=r) return askST(l,r,loca*2);
    SegmentTree TREE,TL,TR;
    TL=askST(l,r,loca*2);
    TR=askST(l,r,loca*2+1);
    TREE.max=max(TL.max,max(TR.max,TL.rmax+TR.lmax));
    TREE.sum=TL.sum+TR.sum;
    TREE.lmax=max(TL.lmax,TL.sum+TR.lmax);
    TREE.rmax=max(TR.rmax,TR.sum+TL.rmax);
    return TREE;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k,x,y;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>A[i];
    buildST(0,n-1,1);
    while(m--)
    {
        cin>>k>>x>>y;
        if(k&1)
        {
            if(x>y) swap(x,y);
            cout<<askST(x-1,y-1,1).max<<endl;
        }
        else
        {
            A[x-1]=y;
            changeST(x-1,1);
        }
    }
}
