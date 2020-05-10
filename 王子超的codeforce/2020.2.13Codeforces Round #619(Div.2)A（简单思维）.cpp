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
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        char a[1000],b[1000],c[1000];
        cin.getline(a,1000);
        cin.getline(b,1000);
        cin.getline(c,1000);
        int len=strlen(a);
        int flag=1;
        for(int i=0;i<len;i++)
        {
            if(c[i]!=a[i]&&c[i]!=b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}



