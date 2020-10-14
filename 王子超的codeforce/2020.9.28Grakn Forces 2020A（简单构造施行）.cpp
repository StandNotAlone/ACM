#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int a[107],b[107],c[107];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];
        int now=-1;
        for(int i=0;i+1<n;i++)
        {
            if(a[i]!=now) now=a[i];
            else if(b[i]!=now) now=b[i];
            else now=c[i];
            cout<<now<<' ';
        }
        if(a[n-1]!=now&&a[n-1]!=a[0]) now=a[n-1];
        else if(b[n-1]!=now&&b[n-1]!=a[0]) now=b[n-1];
        else now=c[n-1];
        cout<<now<<endl;
    }
}