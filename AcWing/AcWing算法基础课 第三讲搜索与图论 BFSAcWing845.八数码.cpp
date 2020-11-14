#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string tar="12345678x",now;
unordered_map<string,int>M;
struct Node
{
    string s;
    int x,dis;
};

int bfs()
{
    queue<Node>Q;
    int temp=-1;
    for(int i=0;i<9;i++) if(now[i]=='x') temp=i;
    Q.push({now,temp,0});
    while(Q.size())
    {
        Node node=Q.front();Q.pop();
        if(node.s==tar) return node.dis;
        if(M.find(node.s)!=M.end()) continue;
        else M[node.s]=1;
        if(node.x>2)
        {
            string s=node.s;
            swap(s[node.x],s[node.x-3]);
            Q.push({s,node.x-3,node.dis+1});
        }
        if(node.x<6)
        {
            string s=node.s;
            swap(s[node.x],s[node.x+3]);
            Q.push({s,node.x+3,node.dis+1});
        }
        if(node.x%3!=2)
        {
            string s=node.s;
            swap(s[node.x],s[node.x+1]);
            Q.push({s,node.x+1,node.dis+1});
        }
        if(node.x%3)
        {
            string s=node.s;
            swap(s[node.x],s[node.x-1]);
            Q.push({s,node.x-1,node.dis+1});
        }
    }
    return -1;
}

int32_t main()
{
    IOS
    for(int i=0;i<9;i++)
    {
        char c;cin>>c;
        now+=c;
    }
    cout<<bfs()<<endl;
}
