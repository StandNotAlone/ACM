#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
ll dp[60][60];
string s;


int net[60];
bool flag[30];

void getnet(string s){
    int len=s.size();
    net[0]=-1;
    for(int i=1,j=-1;i<len;i++){
        while(j>-1&&s[i]!=s[j+1]) j=net[j];
        if(s[i]==s[j+1]) j++;
        net[i]=j;
    }
}

int main(){
    IOS
    cin>>n>>s;
    getnet(s);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]*25%mod;
        dp[i][1]=dp[i-1][0];
        for(int j=1;j<s.size();j++){
            int cnt=26;
            memset(flag,0,sizeof(flag));
            int now=j-1;
            while(1){
                if(!flag[s[now+1]-'a']){
                    flag[s[now+1]-'a']=1;
                    cnt--;
                    dp[i][now+2]=(dp[i][now+2]+dp[i-1][j])%mod;
                }
                if(now==-1) break;
                now=net[now];
            }
            dp[i][0]=(dp[i][0]+dp[i-1][j]*cnt)%mod;
        }
    }
    ll ans=0;
    for(int i=0;i<s.size();i++) ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;
}
