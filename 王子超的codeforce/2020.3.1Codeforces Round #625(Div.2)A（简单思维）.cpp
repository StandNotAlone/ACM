#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int r[110],b[110];
    for(int i=0;i<n;i++) cin>>r[i];
    for(int j=0;j<n;j++) cin>>b[j];
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        if(r[i]!=b[i])
        {
            if(r[i]==1) sum1++;
            else sum2++;
        }
    }
    if(sum1==0) cout<<"-1"<<endl;
    else 
    {
        sum2++;
        int cas=0;
        if(sum2%sum1) cas++;
        sum1=sum2/sum1+cas;
        cout<<sum1<<endl;
    }
}


