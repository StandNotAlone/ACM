#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

unsigned ll hsh[maxn],cas[maxn];

int32_t main()
{
    IOS
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i) hsh[i]=hsh[i-1]*131;
        else hsh[i]=1;
        cas[i+1]=cas[i]*131+s[i];
    }
    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(cas[r1]-cas[l1-1]*hsh[r1-l1+1]==cas[r2]-cas[l2-1]*hsh[r2-l2+1]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
