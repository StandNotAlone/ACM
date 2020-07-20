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

int x[maxn];
int y[maxn];
int tot;
int n;

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    scanf("%d",&n);
    while(n--)
    {
        tot=0;
        int a;
        scanf("%d",&a);
        for(int i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                int temp=0;
                while(a%i==0)
                {
                    a/=i;
                    temp++;
                }
                x[tot]=i;
                y[tot++]=temp;
            }
        }
        if(a>1)
        {
            x[tot]=a;
            y[tot++]=1;
        }
        for(int i=0;i<tot;i++)
            printf("%d %d\n",x[i],y[i]);
        printf("\n");
    }
}


