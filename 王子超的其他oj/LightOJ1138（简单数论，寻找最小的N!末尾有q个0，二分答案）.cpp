#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int cal(int x)
{
    int ret=0;
    while(x)//计算x!分解质因数后有多少个5
    {
        ret+=x/5;
        x/=5;
    }
    return ret;
}

int main()
{
    IOS;//使用之后不要混用cin和scanf printf
    int t;cin>>t;
    for(int CASE=1;CASE<=t;CASE++)
    {
        int m;cin>>m;
        int l=5,r=5e8;//右边界开一个足够大的就行了，直接5乘以最大的m的范围必够，不需要再多过脑子
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(cal(mid)<m) l=mid+1;
            else r=mid;
        }
        cout<<"Case "<<CASE<<": ";
        if(cal(l)==m) cout<<l<<endl;
        else cout<<"impossible"<<endl;
    }
}

