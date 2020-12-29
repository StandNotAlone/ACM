#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int numr=0,numb=0;
        char a[1007],b[1007];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]>a[i]) numb++;
            if(b[i]<a[i]) numr++;
        }
        if(numr>numb) cout<<"RED"<<endl;
        else if(numr<numb) cout<<"BLUE"<<endl;
        else cout<<"EQUAL"<<endl;
    }
}
