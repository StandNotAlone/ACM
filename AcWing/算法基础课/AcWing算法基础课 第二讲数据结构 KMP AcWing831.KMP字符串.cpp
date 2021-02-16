#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

int n,m;
int net[maxn];
int cas[1000007];
string P,S;

void getnet(string s)
{
    int len=s.size();
    net[0]=-1;
    for(int i=1,j=-1;i<len;i++)
    {
        while(j>-1&&s[i]!=s[j+1]) j=net[j];
        if(s[i]==s[j+1]) j++;
        net[i]=j;
    }
}

void KMP(string a,string b)//计算字符串b[1-i]的部分的后缀与字符串a的前缀最大匹配长度
{
    getnet(b);
    int lena=a.size(),lenb=b.size();
    for(int i=0,j=-1;i<lena;i++)
    {
        while(j>-1&&(j==lenb-1||a[i]!=b[j+1])) j=net[j];
        if(a[i]==b[j+1]) j++;
        cas[i]=j;
    }
}

int32_t main()
{
    IOS;
    cin>>n>>P>>m>>S;
    KMP(S,P);
    vector<int>ans;
    for(int i=0;i<m;i++) if(cas[i]==n-1) ans.push_back(i-n+1);
    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}
