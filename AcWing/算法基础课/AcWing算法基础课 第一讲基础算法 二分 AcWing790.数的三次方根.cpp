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
const double eps=1e-8;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    double n;
    scanf("%lf",&n);
    double l=-100,r=100;
    while(r-l>eps)
    {
        double mid=(l+r)/2;
        if(mid*mid*mid<n) l=mid;
        else r=mid;
    }
    printf("%lf\n",l);
}


