#include<bits/stdc++.h>
#include<iomanip>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ifstream f1("/Users/wangzichao/Documents/code/ACM/2021.3.7蓝桥杯校赛/1.in");
ofstream f2("/Users/wangzichao/Documents/code/ACM/2021.3.7蓝桥杯校赛/1.out");
const int maxn=1e6+7;

bool field[2][maxn];
int n,m;

int cal(int x,int y)
{
    if(!field[x][y]) return 0;
    int ret=0;
    for(int i=-1;i<=1;i++)
        if(field[!x][y+i]) ret++;
    return ret;
}

void print(int cas)
{
    if(cas) f2<<"You are the worst boyfriend."<<endl;
    else f2<<"I'm the worst boyfriend.Please forgive me."<<endl;
}

int main()
{
    IOS
    srand((unsigned)time(NULL));
    f1>>n;
    int cas=0;
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)
        {
            f1>>field[i][j];
            if(field[i][j]) cas+=cal(i,j);
        }
    print(cas);
    f1>>m;
    while(m--)
    {
        int x,y;f1>>x>>y;x--;
        cas-=cal(x,y);
        field[x][y]=!field[x][y];
        cas+=cal(x,y);
        print(cas);
    }
}

