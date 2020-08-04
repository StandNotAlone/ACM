#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct Mat
{
    ll a[65][65];
    void init(){memset(a,0,sizeof(a));}
};

Mat operator *(Mat a,Mat b)
{
    Mat ans;ans.init();
    for(int i=0;i<65;i++)
        for(int j=0;j<65;j++)
            for(int k=0;k<65;k++)
                ans.a[i][j]+=a.a[i][k]*b.a[k][j];
    return ans;
}

Mat qpow(Mat a,ll p)
{
    Mat ret;
    ret.init();
    for(int i=0;i<65;i++) ret.a[i][i]=1;
    while(p)
    {
        if(p&1) ret=ret*a;
        a=a*a;
        p>>=1;
    }
    return ret;
}

ll n,m,t,act;
string ope;
string field[10];
Mat cas[60];

int32_t main()
{
    IOS
    cin>>n>>m>>t>>act;
    vector<ll>ans(n*m+1,0);
    ans[0]=1;
    string temp;
    ope.clear();
    for(ll i=0;i<n;i++)
    {
        cin>>temp;
        ope+=temp;
    }
    for(ll i=0;i<act;i++)
    {
        cin>>temp;
        field[i].clear();
        while(field[i].size()<60) field[i]+=temp;
    }
    for(ll i=0;i<60;i++)
    {
        cas[i].init();
        cas[i].a[0][0]=1;
        for(ll j=1;j<=n*m;j++)
        {
            char c=field[ope[j-1]-'0'][i];
            if(c>='0'&&c<='9') cas[i].a[0][j]=c-'0',cas[i].a[j][j]=1;
            else if(c=='N'&&j-m>0) cas[i].a[j][j-m]=1;
            else if(c=='S'&&j+m<=n*m) cas[i].a[j][j+m]=1;
            else if(c=='W'&&(j-1)%m) cas[i].a[j][j-1]=1;
            else if(c=='E'&&j%m) cas[i].a[j][j+1]=1;
        }
    }
    Mat now=cas[0];
    for(ll i=1;i<60;i++) now=now*cas[i];
    now=qpow(now,t/60);
    t%=60;
    for(int i=0;i<t;i++) now=now*cas[i];
    ll out=0;
    for(int i=1;i<65;i++) out=max(out,now.a[0][i]);
    cout<<out<<endl;
}


