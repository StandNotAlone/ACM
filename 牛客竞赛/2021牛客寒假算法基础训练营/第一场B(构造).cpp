#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int n=50000;

int main()
{
    ll k;
    scanf("%lld",&k);

    ll num=k/n;
    ll ret=k%n;
    for(int i=1;i<=n;i++)
    {
        printf("(");
        if(i==ret) printf(")");
    }
    for(int i=1;i<=num;i++) printf(")");
}
