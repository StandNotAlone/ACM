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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int i,a;
        scanf("%d",&a);
        for(i=2;i<=a/i;i++)
            if(a%i==0) break;
        if(i<=a/i||a==1) printf("No\n");
        else printf("Yes\n");
    }
}


