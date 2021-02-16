#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll num[maxn],net[maxn],pre[maxn];
ll head,ed,tar;

void init()
{
    head=ed=0;
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
        string ope;
        cin>>ope;
        if(ope[0]=='L')
        {
            cin>>num[tar];
            net[tar]=head;
            pre[head]=tar;
            head=tar++;
            if(!ed) ed=head;
        }
        if(ope[0]=='R')
        {
            cin>>num[tar];
            net[ed]=tar;
            pre[tar]=ed;
            ed=tar++;
            if(!head) head=ed;
        }
        if(ope[0]=='D')
        {
            int k;
            cin>>k;
            net[pre[k]]=net[k];
            pre[net[k]]=pre[k];
            if(k==head) head=net[k];
            if(k==ed) ed=pre[k];
        }
        if(ope[0]=='I')
        {
            int k;
            cin>>k>>num[tar];
            if(ope[1]=='L')
            {
                pre[tar]=pre[k];
                net[tar]=k;
                net[pre[k]]=tar;
                pre[k]=tar;
                if(k==head) head=tar;
            }
            else
            {
                pre[tar]=k;
                net[tar]=net[k];
                pre[net[k]]=tar;
                net[k]=tar;
                if(k==ed) ed=tar;
            }
            tar++;
        }
    }
    bool flag=0;
    while(1)
    {
        if(!head) break;
        if(flag) cout<<' ';
        flag=1;
        cout<<num[head];
        head=net[head];
    }
    cout<<endl;
}
