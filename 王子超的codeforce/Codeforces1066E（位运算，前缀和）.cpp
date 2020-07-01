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
const ll mod=998244353;

//�����Ŀ����Ҫ��������ÿ�ε��β������ۼ�ֵ����ȥ��ע���ڶ�������s1�е�ÿһ��1��Ӧ�ܹ��ᱻ���㼸��

//��Ϊ��λ�����㣬���Ҷ�������s1����������������ǲ���ģ���˶�������s1��ÿһλ��1�����ֵ�ǲ���ģ�����ÿ�β����ۼ�ֵ���ܰ�����1ֻ����s1��Ӧλ�ϵ�1

//���s1���Ҳ��һ��������1����ô���볤��ΪL2�Ķ�������s2��s2�ĵ�1-L2λ���ϳ��ֵ�ÿ��1�����s1�Ҳ��һ������1����һ��������õ�1
//���s2���Ҳ�ڶ���������2����ô���ڳ���ΪL2�Ķ�������s2��s2�ĵ�1-(L2-1)λ���ϳ��ֵ�ÿ��1�����s1�Ҳ�ڶ�������1����һ��������õ�1
//.......

//������ǽ���һ��ǰ׺������cal[i]��¼s2���е�1����i��λ���ܹ������˼���1�Ϳ��Լ���s1��ÿһλ1��Ӧ��ϵ����

int32_t main()
{
    IOS;
    ll L1,L2;
    cin>>L1>>L2;
    vec origin(L1+1);
    origin[1]=1;
    for(ll i=2;i<=L1;i++)
    {
        origin[i]=origin[i-1]*2%mod;        //Ԥ����orgin[i]����2^(i-1)��Ҳ���Ƕ������������λ�����λ
    }
    string s1,s2;
    cin>>s1>>s2;
    ll ans=0;
    vec cal(L2+1,0);
    REP(i,L2)
    {
        cal[i]=cal[i-1]+s2[i-1]-'0'; //calǰ׺�����飬��¼s2�����±�1���±�i�ܹ������˼���1
    }
    REP(i,min(L1,L2))                 //ע������ѭ�����������������������Ƚ�С���Ǹ�
    {
        if(s1[L1-i]=='1')
        {
            ans=(origin[i]*cal[L2-i+1]%mod+ans)%mod;
        }
    }
    cout<<ans<<endl;
}


