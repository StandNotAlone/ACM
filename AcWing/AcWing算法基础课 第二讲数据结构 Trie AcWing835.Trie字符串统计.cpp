#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

int n;
char ope;
string s;

int trie[maxn][26],ed[maxn];
int tot=0;

void insert(string s)
{
    int len=s.size(),tar=0;
    for(int i=0;i<len;i++)
    {
        int net=s[i]-'a';
        if(trie[tar][net]==0) trie[tar][net]=++tot;
        tar=trie[tar][net];
    }
    ed[tar]++;
}

int search(string s)
{
    int len=s.size(),tar=0;
    for(int i=0;i<len;i++)
    {
        tar=trie[tar][s[i]-'a'];
        if(tar==0) return 0;
    }
    return ed[tar];
}

int32_t main()
{
    IOS;
    cin>>n;
    while(n--)
    {
        cin>>ope>>s;
        if(ope=='I') insert(s);
        else cout<<search(s)<<endl;
    }
}
