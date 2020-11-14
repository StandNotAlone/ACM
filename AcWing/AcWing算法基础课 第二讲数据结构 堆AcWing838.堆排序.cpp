#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,m;
int num[maxn];

void down(int now)
{
    int net=now*2;
    while(net<=n)
    {
        if(net<n&&num[net]>num[net+1]) net++;
        if(num[net]<num[now])
        {
            swap(num[net],num[now]);
            now=net;net=now*2;
        }
        else break;
    }
}

int32_t main()
{
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=n/2;i;i--) down(i);
    for(int i=0;i<m;i++)
    {
        cout<<num[1]<<' ';
        num[1]=num[n--];
        down(1);
    }
}
