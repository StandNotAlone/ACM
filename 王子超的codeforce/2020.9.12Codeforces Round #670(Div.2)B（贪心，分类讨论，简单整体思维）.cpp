#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<ll>zhengshu,fushu;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            if(x<0) fushu.push_back(x);
            else zhengshu.push_back(x);
        }
        sort(fushu.begin(),fushu.end());
        sort(zhengshu.begin(),zhengshu.end());
        ll ans=-llINF;
        for(ll i=1;i<=5;i+=2)//正数或者0的出现次数为奇数，负数的出现次数为偶数
        {
            ll j=5-i;//i为正数出现次数，j为负数出现次数
            if(zhengshu.size()>=i&&fushu.size()>=j)//此时结果为正数，我们要使得绝对值尽可能大，这样值更大
            {
                ll temp=1;
                for(ll k=1;k<=i;k++) temp*=zhengshu[zhengshu.size()-k];//正数绝对值大的在末尾
                for(ll k=0;k<j;k++) temp*=fushu[k];//负数绝对值大的在开头
                ans=max(ans,temp);
            }
        }
        for(ll i=0;i<5;i+=2)//正数或者0的出现次数为偶数，负数的出现次数为奇数
        {
            ll j=5-i;
            if(zhengshu.size()>=i&&fushu.size()>=j)//此时结果为负数，我们要使得绝对值尽可能小，这样值更大
            {
                ll temp=1;
                for(ll k=0;k<i;k++) temp*=zhengshu[k];//正数绝对值小的在开头
                for(ll k=1;k<=j;k++) temp*=fushu[fushu.size()-k];//负数绝对值小的在末尾
                ans=max(ans,temp);
            }
        }
        zhengshu.clear();
        fushu.clear();
        cout<<ans<<endl;
    }
}
