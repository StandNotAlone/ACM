#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<unordered_set>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e3+7;

string s[1007];
int n,m;
int ansgirl,anscat;

char dir[4][2]=
{
    -1,0,
    1,0,
    0,-1,
    0,1
};

char girl[5]="girl",cat[4]="cat";

void dfsgirl(int x,int y,int deep)
{
    if(deep==3&&s[x][y]=='l') ansgirl++;
    else
    {
        if(s[x][y]==girl[deep])
        {
            for(int i=0;i<4;i++)
            {
                int to_x=x+dir[i][0],to_y=y+dir[i][1];
                if(to_x>=0&&to_x<n&&to_y>=0&&to_y<m) dfsgirl(to_x,to_y,deep+1);
            }
        }
    }
}

void dfscat(int x,int y,int deep)
{
    if(deep==2&&s[x][y]=='t') anscat++;
    else
    {
        if(s[x][y]==cat[deep])
        {
            for(int i=0;i<4;i++)
            {
                int to_x=x+dir[i][0],to_y=y+dir[i][1];
                if(to_x>=0&&to_x<n&&to_y>=0&&to_y<m) dfscat(to_x,to_y,deep+1);
            }
        }
    }
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ansgirl=anscat=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                dfsgirl(i,j,0);
                dfscat(i,j,0);
            }
        cout<<ansgirl<<' '<<anscat<<endl;
    }
}
