#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool flag[30007];

void work()
{
    for(int i=2;i<30007;i++)
    {
        if(!flag[i])
        {
            for(int j=2;j*i<30007;j++) flag[i*j]=1;
        }
    }
}

int main()
{
    IOS
    int t;cin>>t;
    work();
    while(t--)
    {
        int d;cin>>d;
        int x=d+1;
        while(flag[x]) x++;
        int y=x+d;
        while(flag[y]) y++;
        cout<<x*y<<endl;
    }
}
