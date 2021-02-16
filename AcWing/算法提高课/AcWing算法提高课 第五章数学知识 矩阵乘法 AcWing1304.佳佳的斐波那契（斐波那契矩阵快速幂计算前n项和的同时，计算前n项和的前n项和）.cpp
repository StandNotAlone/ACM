#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n,m;

struct Mat
{
    ll a[4][4];
    void init()
    {
        memset(a,0,sizeof(a));
    }
};

Mat operator *(Mat a,Mat b)
{
    Mat ans;ans.init();
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%m;
    return ans;
}

Mat qpow(Mat a,ll p)
{
    Mat ret;ret.init();
    for(int i=0;i<4;i++)
        ret.a[i][i]=1;
    while(p)
    {
        if(p&1) ret=ret*a;
        a=a*a;
        p>>=1;
    }
    return ret;
}

int32_t main()
{
    IOS;
    Mat now;
    now.a[0][0]=1;now.a[0][1]=1;now.a[0][2]=2;now.a[0][3]=3;
    now.a[1][0]=0;now.a[1][1]=1;now.a[1][2]=1;now.a[1][3]=2;
    now.a[2][0]=0;now.a[2][1]=1;now.a[2][2]=2;now.a[2][3]=3;
    now.a[3][0]=0;now.a[3][1]=0;now.a[3][2]=0;now.a[3][3]=1;
    Mat bs=now;
    cin>>n>>m;
    ll p=(n-2)/2;
    now=qpow(now,p);
    ll tot,rest;
    if(n&1)
    {
        rest=now.a[0][3]+now.a[1][3]+now.a[2][3]*2+now.a[3][3]*3;
        now=now*bs;
        tot=now.a[0][1]+now.a[1][1]+now.a[2][1]*2;
    }
    else
    {
        tot=now.a[0][2]+now.a[1][2]+now.a[2][2]*2;
        rest=now.a[0][3]+now.a[1][3]+now.a[2][3]*2+now.a[3][3]*3-tot;
    }
    cout<<(tot%m*n%m-rest%m+m)%m<<endl;
}
