#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1400000;

struct Node
{
    int tar,data;
    friend bool operator <(Node a,Node b)
    {
        return a.data>b.data;
    }
};

int cas[maxn];
int x,n;

void bfs()
{
    priority_queue<Node>Q;
    for(int i=0;i<maxn;i++) cas[i]=INF;
    cas[x]=0;
    Q.push({x,0});
    while(1)
    {
        Node temp=Q.top();
        Q.pop();
        //cout<<temp.data<<' '<<temp.tar<<endl;
        if(temp.data>=cas[n]) break;
        if(temp.data>cas[temp.tar]) continue;
        int to,todata;
        to=temp.tar+1;todata=temp.data+1;
        if(temp.tar<n&&cas[to]>todata&&todata<cas[n])
        {
            cas[to]=todata;
            Q.push({to,todata});
        }
        to=temp.tar-1;
        if(temp.tar&&cas[to]>todata&&todata<cas[n])
        {
            cas[to]=todata;
            Q.push({to,todata});
        }
        if(temp.data+3<cas[0])
        {
            cas[0]=temp.data+3;
            Q.push({0,cas[0]});
        }
        if(temp.tar)
        {
            for(to=temp.tar*2,todata=temp.data+6;to<maxn;to+=temp.tar,todata+=2)
            {
                if(cas[to]>todata)
                {
                    if(todata>=cas[n]) break;
                    cas[to]=todata;
                    Q.push({to,todata});
                }
            }
        }
    }
}

int32_t main()
{
    IOS;
    cin>>x>>n;
    bfs();
    cout<<cas[n]<<endl;
}
