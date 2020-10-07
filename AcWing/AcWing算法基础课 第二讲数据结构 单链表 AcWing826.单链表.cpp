#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll num[maxn],net[maxn];
ll head,tar;

void init()
{
    head=-1;
    tar=1;
}

int32_t main()
{
    IOS;
    init();
    int m;
    cin>>m;
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='H')
        {
            cin>>num[tar];
            net[tar]=head;
            head=tar++;
        }
        else if(c=='I')
        {
            int k;
            cin>>k>>num[tar];
            net[tar]=net[k];
            net[k]=tar++;
        }
        else
        {
            int k;
            cin>>k;
            if(k) net[k]=net[net[k]];
            else head=net[head];
        }
    }
    while(1)
    {
        cout<<num[head];
        head=net[head];
        if(head==-1) break;
        cout<<' ';
    }
    cout<<endl;
}
