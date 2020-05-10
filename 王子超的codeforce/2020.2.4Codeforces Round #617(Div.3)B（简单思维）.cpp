#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
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

//题意为给你n个数，你可以进行无数次操作（包括0次），每次操作可以把其中一个数变成数列中中的另一个数
//询问能否经过若干次操作后将整个数列的和变成奇数

//直接统计下奇数元素和偶数元素的个数，如果奇数个数是奇数则已经和为奇数
//奇数个数为偶数时，必须满足奇数必须存在，并且当奇数存在时存在一个偶数使得进行奇数偶数的变换才能改变整个数列的奇偶性

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,t;
    cin>>t;
    ll num[2010];
    while(t--)
    {
        cin>>n;
        ll sum1=0,sum2=0;
        for(ll i=0;i<n;i++)
        {
            cin>>num[i];
            if(num[i]&1) sum1++;
            else sum2++;
        }
        if(sum1&1) cout<<"YES"<<endl;
        else if(sum1&&sum2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}



