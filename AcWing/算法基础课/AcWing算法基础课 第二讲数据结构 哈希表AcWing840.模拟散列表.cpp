#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;

ll L[maxn];

bool find(ll x)
{
    int tar=(x%maxn+maxn)%maxn;
    while(L[tar]!=llINF)
    {
        if(L[tar]==x) return 1;
        tar=(tar+1)%maxn;
    }
    return 0;
}

int32_t main()
{
    IOS
    for(int i=0;i<maxn;i++) L[i]=llINF;
    int n;
    cin>>n;
    while(n--)
    {
        char c;ll x;
        cin>>c>>x;
        if(c=='I')
        {
            int tar=(x%maxn+maxn)%maxn;
            while(L[tar]!=llINF)
            {
                if(L[tar]==x) break;
                tar=(tar+1)%maxn;
            }
            L[tar]=x;
        }
        else
        {
            if(find(x)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
