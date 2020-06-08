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
#define mp make_pair
#define pb push_back
#define ll long long
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
//ios::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const ll maxn=2e5+7;
const double eps=1e-10;
const ll mod=1e9+7;

ll dir[4][2]=
{
    1,0,
    -1,0,
    0,1,
    0,-1
};

ll n,m;
vector<string>field;

ll sum;

bool judge(ll x,ll y)
{
    if(field[x][y]=='#'||field[x][y]=='B') return 0;    //如果当前位置为墙壁或者坏人所在的位置则为不可走。注意此处要判断是否为坏人位置，虽然下面的判断杜绝了我们走到换人四周的位置
                                                        //但是作为dfs起点的迷宫终点位置可能就在坏人位置旁边
    for(ll i=0;i<4;i++)                                 //我们下一步走的路线不能经过坏人的周围
    {
        ll tempn=x+dir[i][0],tempm=y+dir[i][1];
        if(tempn>=0&&tempn<n&&tempm>=0&&tempm<m)
        {
            if(field[tempn][tempm]=='B') return 0;
        }
    }
    return 1;
}

void dfs(ll x,ll y)
{
    if(!judge(x,y)) return ;
    if(field[x][y]=='G') sum++;
    field[x][y]='#';
    for(ll i=0;i<4;i++)
    {
        ll tempn=x+dir[i][0],tempm=y+dir[i][1];
        if(tempn>=0&&tempn<n&&tempm>=0&&tempm<m)
        {
            dfs(tempn,tempm);
        }
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        field.clear();
        field.resize(n);
        ll numg=0,numb=0;
        at(x,field)
        {
            cin>>x;
            at(y,x)
            {
                if(y=='G') numg++;
                if(y=='B') numb++;
            }
        }
        if(!numg&&!numb) cout<<"Yes"<<endl;
        else if(!numg&&numb) cout<<"Yes"<<endl;
        else
        {
            sum=0;
            dfs(n-1,m-1);
            if(sum==numg) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}


