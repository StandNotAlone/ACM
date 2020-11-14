#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,tot=0,m=0;
int h[maxn],ph[maxn],hp[maxn];

void change(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int now)
{
    int net=now*2;
    while(net<=tot)
    {
        if(net<tot&&h[net+1]<h[net]) net++;
        if(h[net]<h[now])
        {
            change(net,now);
            now=net;net=now*2;
        }
        else break;
    }
}

void up(int now)
{
    while(now>1)
    {
        if(h[now]<h[now/2])
        {
            change(now,now/2);
            now/=2;
        }
        else break;
    }
}

int32_t main()
{
    IOS
    cin>>n;
    string ope;
    while(n--)
    {
        cin>>ope;
        if(ope[0]=='I')
        {
            int x;
            cin>>x;
            h[++tot]=x;
            ph[++m]=tot;hp[tot]=m;
            up(tot);
        }
        else if(ope[0]=='P') cout<<h[1]<<endl;
        else if(ope[0]=='D'&&ope[1]=='M')
        {
            change(1,tot--);
            down(1);
        }
        else if(ope[0]=='D')
        {
            int x;
            cin>>x;
            int tar=ph[x];
            change(ph[x],tot--);
            up(tar);down(tar);
        }
        else
        {
            int k,x;
            cin>>k>>x;
            h[ph[k]]=x;
            up(ph[k]);down(ph[k]);
        }
    }
}