#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
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
    if(cas) printf("You are the worst boyfriend.\n");
    else printf("I'm the worst boyfriend.Please forgive me.\n");
}

int main()
{
    scanf("%d",&n);
    int cas=0;
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&field[i][j]);
            if(field[i][j]) cas+=cal(i,j);
        }
    print(cas);
    scanf("%d",&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        cas-=cal(x,y);
        field[x][y]=!field[x][y];
        cas+=cal(x,y);
        print(cas);
    }
}

