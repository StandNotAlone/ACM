#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<ll,ll> PLL;
const ll maxn=1e4+7;

char a[maxn],b[maxn];

int32_t main()
{
    while(scanf("%s%s",a,b)!=EOF)
    {
        vector<PLL>A,B;
        int lena=strlen(a);
        int lenb=strlen(b);
        int numa=0,numb=0;
        for(int i=0;i<lena;i++)
        {
            if(a[i]=='c')
            {
                A.push_back(PLL(numa,numb));
                numa=numb=0;
            }
            else if(a[i]=='a') numa++;
            else numb++;
        }
        A.push_back(PLL(numa,numb));
        numa=numb=0;
        for(int i=0;i<lenb;i++)
        {
            if(b[i]=='c')
            {
                B.push_back(PLL(numa,numb));
                numa=numb=0;
            }
            else if(b[i]=='a') numa++;
            else numb++;
        }
        B.push_back(PLL(numa,numb));
        if(A.size()!=B.size()) printf("No\n");
        else
        {
            bool flag=1;
            for(int i=0;i<A.size();i++)
            {
                if(abs(A[i].first-B[i].first)%2) flag=0;
                if(abs(A[i].second-B[i].second)%2) flag=0;
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }
}
