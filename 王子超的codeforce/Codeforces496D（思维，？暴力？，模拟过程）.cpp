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
const ll maxn=1e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll n;

ll totA=0,totB=0;
ll casA[maxn*2],casB[maxn*2];   //cas[i]��¼A��B�����˵�i��ʤ�������ڵڼ�������

ll tot=0;

struct Node
{
    ll round,score;
};

Node node[maxn];

bool cmp(Node a,Node b)
{
    if(a.round<b.round) return 1;
    if(a.round==b.round&&a.score<b.score) return 1;
    return 0;
}

int32_t main()
{
    IOS;
    cin>>n;
    for(ll i=1;i<2*maxn;i++) casA[i]=casB[i]=llINF; //ע�����￪�����������Լ���ʼ��ֵ��������Ƚϣ�
    bool flagA=0,flagB=0;                           //��¼���һ��ʤ����A����B�����������˭����ʤ����
    for(ll i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        if(x==1) casA[++totA]=i;
        else casB[++totB]=i;
        if(i==n)
        {
            if(x==1) flagA=1;
            else flagB=1;
        }
    }
    for(ll i=n;i>=1;i--)//������Ȼ����for��һ��n����������ѭ�����ֵĲ���Ϊi��Ҳ����˵�ܹ��ĸ��Ӷ�ʵ������n/1+n/2+n/3+....+n/n=nlogn
    {
        ll winA=0,winB=0,tarA=0,tarB=0;//winΪ��ʤ������tarAΪ��ǰA�Ѿ�ʤ���˼���
        ll now=1;   //now��¼��ǰ�Ѿ��������ݵ���һ��λ�ã������Ƿ�����ѭ��
        bool flag=1;    //��Ǳ����Ƿ�ɹ��ҵ����ʵľ���
        while(now<=n)
        {
            if(casA[tarA+i]==llINF&&casB[tarB+i]==llINF)    //���A��B��һ����ʤ��λ�þ��Ѿ�������n��������жϷ��������֮ǰ�����������Ԥ����
            {
                flag=0;
                break;
            }
            if(casA[tarA+i]<casB[tarB+i])   //tarAΪ�Ѿ�ʤ���ľ�������ô�����Ҫ��Ӯһ�ֵĻ�������Ӧ����tarA+i���Ƚ����ߵ����±�С����һ��Ϊ����ʤ����
            {
                winA++;
                tarA+=i;
                tarB=casA[tarA]-tarA;   //casA[tarA]����Aʤ��tarA�ֵ������±�λ�ã�Ҳ���ǵ�ǰ���е��ܾ�������ȥAʤ���ľ���Ҳ����Bʤ���ľ�����
                now=casA[tarA]+1;
            }
            else
            {
                winB++;
                tarB+=i;
                tarA=casB[tarB]-tarB;
                now=casB[tarB]+1;
            }
        }
        if(winA==winB) flag=0;  //����ƽ�ֵ����
        if(winA>winB&&flagB) flag=0;    //����Aʤ���������һ�ֻ�ʤ����B�����
        if(winA<winB&&flagA) flag=0;    //����Bʤ���������һ�ֻ�ʤ����A�����
        if(flag)
        {
            node[++tot].round=max(winA,winB);
            node[tot].score=i;
        }
    }
    sort(node,node+tot,cmp);
    cout<<tot<<endl;
    if(tot)
    {
        for(ll i=1;i<=tot;i++) cout<<node[i].round<<' '<<node[i].score<<endl;
    }
}


