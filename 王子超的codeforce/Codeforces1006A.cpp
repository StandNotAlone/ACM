#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int n;cin>>n;
    while(n--)
    {
        int a;cin>>a;
        if(a&1) cout<<a<<' ';
        else cout<<a-1<<' ';//CF对格式的要求不是非常严格，只有单行输出的时候，末尾空格和换行不做严格要求
    }
}
