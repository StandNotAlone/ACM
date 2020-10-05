#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;
const ll maxn=2e5+7;

struct Node
{
    ll a,ab,abc;
};

Node dp[maxn][3];//dp[i][j]表示第i个字符构造j的情况下，a/ab/abc各自出现了几次，j=0代表构造字符'a'，j=1代表构造'b'，j=2代表构造'c'
//当s[i]是个确定的字符时，只转移到dp[i][0]上
int n;
ll cas=1;//记录3^k，用于构造'a'时的转移
char s[maxn];

void trans(int x,int y)
{
    for(int i=0;i<3;i++)
    {
        dp[x][y].a=(dp[x][y].a+dp[x-1][i].a)%mod;
        dp[x][y].ab=(dp[x][y].ab+dp[x-1][i].ab)%mod;
        dp[x][y].abc=(dp[x][y].abc+dp[x-1][i].abc)%mod;
    }
}

void transa(int x,int y)//构造a时的转移方式
{
    trans(x,y);
    dp[x][y].a=(dp[x][y].a+cas)%mod;
}

void transb(int x,int y)//构造b时的转移方式
{
    trans(x,y);
    dp[x][y].ab=(dp[x][y].ab+dp[x-1][0].a+dp[x-1][1].a+dp[x-1][2].a)%mod;
}

void transc(int x,int y)//构造c时的转移方式
{
    trans(x,y);
    dp[x][y].abc=(dp[x][y].abc+dp[x-1][0].ab+dp[x-1][1].ab+dp[x-1][2].ab)%mod;
}

int32_t main()
{
    IOS;
    cin>>n>>(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
        {
            transa(i,0);
            transb(i,1);
            transc(i,2);
            cas=cas*3%mod;
        }
        else
        {
            if(s[i]=='a') transa(i,0);
            if(s[i]=='b') transb(i,0);
            if(s[i]=='c') transc(i,0);
        }
    }
    cout<<(dp[n][0].abc+dp[n][1].abc+dp[n][2].abc)%mod<<endl;
}
