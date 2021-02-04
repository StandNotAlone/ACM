#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

ll fib[maxn];

int main()
{
	fib[1]=2;fib[2]=3;
	for(int i=3;i<=41;i++) fib[i]=fib[i-1]+fib[i-2];
	for(int i=42;i<=100000;i++) fib[i]=1;
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i>1) printf(" ");
		printf("%lld",fib[i]);
	}
	printf("\n");
}
