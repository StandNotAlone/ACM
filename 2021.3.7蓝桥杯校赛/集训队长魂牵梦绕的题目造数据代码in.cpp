#include<bits/stdc++.h>
#include<iomanip>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ifstream f1("/Users/wangzichao/Documents/code/ACM/2021.3.7蓝桥杯校赛/1.in");
ofstream f2("/Users/wangzichao/Documents/code/ACM/2021.3.7蓝桥杯校赛/10.in");
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

void build(int n)
{
    int cas=0;
    int lim=100;
//    for(int i=0;i<2;i++)
//        for(int j=1;j<=n;j++)
//            field[i][j]=0;
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            field[i][j]=rand()%2;
            if(field[i][j]) lim--;
            if(lim<=0) field[i][j]=0;
            cas+=cal(i,j);
        }
    }

    f2<<n<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>1) f2<<' ';
            f2<<field[i][j];
        }
        f2<<endl;
    }

    int ans1=0,ans2=0;//ans1记录无法走到的答案有多少个
    int m=1000000;
    int x,y;
    f2<<m<<endl;
    while(m--)
    {
        int temp=0;
        if(ans1-ans2>10)
        {
            x=rand()%2;
            y=rand()%n+1;
            while(x==0&&y==1||x==1&&y==n||field[x][y]==0)
            {
                temp++;
                if(temp>100) break;
                x=rand()%2;
                y=rand()%n+1;
            }
        }
        else if(ans2-ans1>10)
        {
            x=rand()%2;
            y=rand()%n+1;
            while(x==0&&y==1||x==1&&y==n||field[x][y]==1)
            {
                temp++;
                if(temp>100) break;
                x=rand()%2;
                y=rand()%n+1;
            }
        }
        else
        {
            temp++;
            x=rand()%2;
            y=rand()%n+1;
            while(x==0&&y==1||x==1&&y==n)
            {
                temp++;
                if(temp>100) break;
                x=rand()%2;
                y=rand()%n+1;
            }
        }
        f2<<x+1<<' '<<y<<endl;
        cas-=cal(x,y);
        field[x][y]=!field[x][y];
        cas+=cal(x,y);
        if(cas) ans1++;
        else ans2++;
    }
}

int main()
{
    IOS
    srand((unsigned)time(NULL));
    build(1000000);
}

/*
4
0 1 0 0
0 0 1 0
6
2 2
1 3
2 3
2 3
1 2
1 3
*/
