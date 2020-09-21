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
const ll maxn=4e4+7;

double r[maxn],x[maxn],y[maxn];
vector<pair<double,int>>casx;
int n;
set<pair<double,int>>S;
vector<int>ans;

bool check(int a,int b)
{
    double X=x[a]-x[b];
    double Y=y[a]-y[b];
    return X*X+Y*Y<=r[a]*r[a];
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        S.clear();
        ans.clear();
        casx.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&r[i],&x[i],&y[i]);
            casx.push_back(make_pair(x[i]-r[i],i));
            casx.push_back(make_pair(x[i]+r[i],i+n));
        }
        sort(casx.begin(),casx.end());
        for(int i=0;i<2*n;i++)
        {
            int tar=casx[i].second%n;
            if(casx[i].second<n)
            {
                set<pair<double,int>>::iterator temp=S.lower_bound(make_pair(y[tar],tar));
                if(temp!=S.end()&&check((*temp).second,tar)) continue;
                if(temp!=S.begin()&&check((*(--temp)).second,tar)) continue;
                ans.push_back(tar);
                S.insert(make_pair(y[tar],tar));
            }
            else S.erase(make_pair(y[tar],tar));
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",(int)ans.size());
        for(int i=0;i<ans.size();i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]+1);
        }
        printf("\n");
    }
}
