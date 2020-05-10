#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
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
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
#define vec vector<ll>
#define mat vector<vector<ll>>
//cout<<fixed<<setprecision(6)<<
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
const int maxn=INF;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,c;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        int ans=0;
        if(a)
        {
            a--;
            ans++;
        }
        if(b)
        {
            b--;
            ans++;
        }
        if(c)
        {
            c--;
            ans++;
        }
        if(a&&b&&c)
        {
            if(a>2&&b>2&&c>2) ans+=4;
            else if(a>1&&b>1&&c>1) ans+=3;
            else if(a>1||b>1||c>1) ans+=2;
            else ans+=1;
        }
        else if(a&&b||a&&c||b&&c) ans++;
        cout<<ans<<endl;
    }
}



