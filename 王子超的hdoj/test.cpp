#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
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
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
 
#define local
#ifdef local
#endif
 
#define maxn
using namespace std;
int main()
{
    int t,ans=0,l=0,r=0;
    char c;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        c=getchar();
        if(c=='L')l++;
        if(c=='R')r++;
    }
    printf("%d\n",l+r+1);
}