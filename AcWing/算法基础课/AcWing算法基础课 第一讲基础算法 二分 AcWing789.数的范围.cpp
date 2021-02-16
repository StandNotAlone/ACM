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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,q,k;
int num[maxn];

int search1()
{
    int l=0,r=n-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(num[mid]<k) l=mid+1;
        else r=mid;
    }
    if(num[l]!=k) l=-1;
    return l;
}

int search2()
{
    int l=0,r=n-1;
    while(l<r)
    {
        int mid=((l+r)>>1)+1;
        if(num[mid]>k) r=mid-1;
        else l=mid;
    }
    if(num[l]!=k) l=-1;
    return l;
}

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&k);
        int l=search1();
        int r=search2();
        printf("%d %d\n",l,r);
    }
}


