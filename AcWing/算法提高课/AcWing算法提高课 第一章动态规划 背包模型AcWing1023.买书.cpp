#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
ll dp[1007];
int num[4]={10,20,50,100};

int main(){
    IOS
    cin>>n;
    dp[0]=1;
    for(int i=0;i<4;i++)
        for(int j=num[i];j<=n;j++)
            dp[j]+=dp[j-num[i]];
    cout<<dp[n]<<endl;
}
