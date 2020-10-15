#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;

vector<int>origin[26];
int revese[maxn];//reverse[i]记录翻转后的第i个位置，在原来的字符串中是第几个位置
int n;
string s;

int tree[maxn];
void add(int x,int v)
{
    for(;x<=n;x+=x&-x) tree[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(;x>0;x-=x&-x) ret+=tree[x];
    return ret;
}

int32_t main()
{
    IOS;
    cin>>n>>s;
    for(int i=0;i<n;i++) origin[s[i]-'a'].push_back(i);//26个字母记录从左往右的下标
    for(int i=0;i<26;i++)
    {
        int len=origin[i].size();
        for(int j=0;j<len;j++) revese[n-origin[i][len-j-1]]=origin[i][j]+1;//同一个字母，按照翻转后所在的位置，从左往右依次贪心放进去
        //由于要用树状数组，所以这里让下标变成从1开始
    }
    ll ans=0;
    for(int i=1;i<=n;i++)//利用树状数组求个逆序对，就是冒泡从原序列变成当前序列所需的最少操作次数了
    {
        ans+=i-1-sum(revese[i]);
        add(revese[i],1);
    }
    cout<<ans<<endl;
}
