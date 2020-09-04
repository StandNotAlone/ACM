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
#define ll long long
#define llINF 9223372036854775807
using namespace std;
const int maxn=5007;

struct Line
{
    double up,down;
}line[maxn];

int n,m;
double leftx,rightx,upy,downy;
int ans[maxn];

bool check(int i,double x,double y)
{
    if(line[i].down==line[i].up) return line[i].up>x;
    double tar=line[i].down+(y-downy)/(upy-downy)*(line[i].up-line[i].down);
    return tar>x;
}

int main()
{
    int cal=0;
    while(1)
    {
        scanf("%d",&n);
        if(!n) break;
        scanf("%d%lf%lf%lf%lf",&m,&leftx,&upy,&rightx,&downy);
        if(cal++) printf("\n");
        for(int i=0;i<n;i++) scanf("%lf%lf",&line[i].up,&line[i].down);
        line[n].up=line[n].down=rightx;
        for(int i=0;i<m;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            int l=0,r=n;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(check(mid,x,y)) r=mid;
                else l=mid+1;
            }
            ans[l]++;
        }
        for(int i=0;i<=n;i++) printf("%d: %d\n",i,ans[i]);
        for(int i=0;i<=n;i++) ans[i]=0;
    }
}
//二分