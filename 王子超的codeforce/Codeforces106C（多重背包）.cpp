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
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define ft first
#define sd second
#define endl "\n"
#define mp make_pair
#define pb push_back
#define ll long long
#define int long long
#define vec vector<ll>
#define mat vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define _rep(i,n) for(ll i=n-1;i>=0;i--)
#define REP(i,n) for(ll i=1;i<=(ll)(n);i++)
#define _REP(i,n) for(ll i=n;i>0;i--)
#define at(x,n) for(auto &x:n)
//cout<<fixed<<setprecision(6)<<
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1("/Users/wangzichao/Documents/wzc.in");
//ofstream f2("/Users/wangzichao/Documents/wzc.out");
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int read()      //���������
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

using namespace std;
#define local
#ifdef local
#endif
const ll maxn=1e3+7;
const double eps=1e-10;
const ll mod=1e9+7;

//ͦ���һ�����ر���dp


ll w[maxn],v[maxn],num[maxn];
//w[i]��������һ�ݵ�i�ָ����Ҫ�����������v[i]Ϊ�۳�һ�ݵ�i�ָ���õ�����
//num[i]Ϊ��i�ָ������ϽǶȿ�������������������ai/bi���ɵõ�

int32_t main()
{
    IOS;
    ll n,m,c0,d0;
    cin>>n>>m>>c0>>d0;
    ll a,b;
    for(ll i=1;i<=m;i++)
    {
        cin>>a>>b;
        cin>>w[i]>>v[i];
        num[i]=a/b;
    }
    w[m+1]=c0;v[m+1]=d0;num[m+1]=llINF; //���ӵ�m+1�ָ�㣬Ҳ���������ϵĸ�㣬��������Ϊ�����
    ll dp[13][maxn];    //dp[i][j]��������ǰi�ָ�㣬ʹ��j�����Ż�õ��������
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=m+1;i++)  //i�ǵ�ǰ�����ĸ������
    {
        for(ll j=0;j<=n;j++)        //j�ǵ�ǰ�ĳ�ʼ���ŷ���
        {
            for(ll k=0;j-k*w[i]>=0&&k<=num[i];k++)      //k�ǵ�ǰ����������ٷݣ�j-k*w[i]>=0��֤�����Ź��ã�k<=num[i]��֤�����Ϲ���
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]);    //���ر�����״̬ת�Ʒ����Լ�ȥ������߱��˲��Ͱ�.
            }
        }
    }
    cout<<dp[m+1][n]<<endl;
}


