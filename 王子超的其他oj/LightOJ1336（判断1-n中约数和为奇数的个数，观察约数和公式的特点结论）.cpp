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
const ll maxn=1e6+10;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int t;
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",CASE,n-(ll)sqrt(n)-(ll)sqrt(n/2));
    }
}


