#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e6+7;

int n;
int net[maxn];
string S;

//这里下标是从0开始的
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

int32_t main()
{
    IOS;
    int cas=0;
    while(cin>>n,n)
    {
        cas++;
        cin>>S;
        getnet(S);
        cout<<"Test case #"<<cas<<endl;
        for(int i=1;i<S.size();i++)
        {
            if((i+1)%(i-net[i])==0&&(i+1)/(i-net[i])>1) cout<<i+1<<' '<<(i+1)/(i-net[i])<<endl;
        }
        cout<<endl;
    }
}
