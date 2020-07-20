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
    int t;
    scanf("%d",&t);
    for(int CASE=1;CASE<=t;CASE++)
    {
        bool f=0;
        char s[250];
        ll b;
        getchar();
        scanf("%s%lld",s,&b);
        int tar=0;
        b=abs(b);
        if(s[0]=='-') tar++;
        if(s[tar]==0) f=1;
        else
        {
            ll ans=0;
            ll len=strlen(s);
            while(tar<len)
            {
                ans=(ans*10%b+s[tar]-'0')%b;
                tar++;
            }
            if(ans==0) f=1;
        }
        printf("Case %d: ",CASE);
        if(f) printf("divisible\n");
        else printf("not divisible\n");
    }
}


