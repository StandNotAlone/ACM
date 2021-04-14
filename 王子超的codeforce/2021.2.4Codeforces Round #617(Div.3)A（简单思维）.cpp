#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int num1=0,num2=0;
        while(n--)
        {
            int x;cin>>x;
            if(x&1) num1++;//判断x是奇数还是偶数
            else num2++;
        }
        if(num1&1) cout<<"YES"<<endl;//如果num1是奇数，原数组中奇数出现了奇数次，数组总和为奇数，无需操作已经满足
        else if(num1&&num2) cout<<"YES"<<endl;//num1是偶数，原数组总和为偶数，需要奇数和偶数均存在才能改变总和的奇偶性
        else cout<<"NO"<<endl;
    }
}
