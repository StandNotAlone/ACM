#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n,m;

struct Mat
{
    ll a[3][3];
    void init()
    {
        memset(a,0,sizeof(a));
    }
};

Mat operator *(Mat a,Mat b)
{
    Mat ans;ans.init();
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%m;
    return ans;
}

Mat qpow(Mat a,ll p)
{
    Mat ret;ret.init();
    for(int i=0;i<3;i++)
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
    now.a[0][0]=1;now.a[0][1]=1;now.a[0][2]=2;
    now.a[1][0]=0;now.a[1][1]=1;now.a[1][2]=1;
    now.a[2][0]=0;now.a[2][1]=1;now.a[2][2]=2;
    cin>>n>>m;
    ll p=(n-1)/2;
    now=qpow(now,p);
    if(n&1) cout<<(now.a[0][1]+now.a[1][1]+2*now.a[2][1])%m<<endl;
    else cout<<(now.a[0][2]+now.a[1][2]+2*now.a[2][2])%m<<endl;
}
