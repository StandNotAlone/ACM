#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    ll ans=1;
    for(int i=1;i<=n/2;i++) ans=ans*(n-i+1)/i;//计算C(n/2,n)，划分成两组
    for(int i=2;i<n/2;i++) ans*=i*i;//乘上两边n!，并且除掉两个n，化简后便是该循环。此处为两组当中排列方式不同的情况，除掉n是因为循环相同的排列也属于排列方式相同
    cout<<ans/2<<endl;//A,B和B,A的分法重复，除以2
}
