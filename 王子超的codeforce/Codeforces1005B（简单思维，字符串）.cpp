#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int main()
{
    IOS;
    string a,b;
    cin>>a>>b;
    ll lena=a.size();
    ll lenb=b.size();
    ll temp=1;
    while(lena-temp>=0&&lenb-temp>=0)
    {
        if(a[lena-temp]==b[lenb-temp]) temp++;
        else break;
    }
    cout<<lena+lenb-2*(temp-1)<<endl;
}
