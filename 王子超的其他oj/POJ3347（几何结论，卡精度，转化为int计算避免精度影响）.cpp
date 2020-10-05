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
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
using namespace std;

int len[60];
int tar[60];
int n;

int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(!n) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&len[i]);
            tar[i]=len[i];
            for(int j=1;j<i;j++)
                tar[i]=max(tar[i],min(len[j],len[i])*2+tar[j]);
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            int l=tar[i]-len[i],r=tar[i]+len[i];
            for(int j=1;j<i;j++)
                if(len[j]>len[i]) l=max(l,tar[j]+len[j]);
            for(int j=i+1;j<=n;j++)
                if(len[j]>len[i]) r=min(r,tar[j]-len[j]);
            if(l<r) ans.push_back(i);
        }
        for(int i=0;i<ans.size();i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
}
