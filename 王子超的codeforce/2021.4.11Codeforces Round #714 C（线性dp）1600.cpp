#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
ll dp[maxn][10];//dp[i][j]代表从数值9作为起始值，进行i次操作后，数值9有多少个
ll len[maxn];//len[i]代表9被操作i次后的长度

int main(){
    IOS
    dp[0][9]=1;
    for(int i=1;i<=200000;i++){
        for(int j=1;j<=9;j++) dp[i][j]=dp[i-1][j-1];//数值1-9都可以从上次操作得到的0-8依次+1转移过来
        dp[i][0]=dp[i-1][9];//数值0是从9+1转移过来
        dp[i][1]=(dp[i][1]+dp[i-1][9])%mod;//9+1还会得到一个1
        for(int j=0;j<=9;j++) len[i]=(len[i]+dp[i][j])%mod;//累加当前0-9总共有几个，即第i次操作后的长度
    }
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        ll ans=0;
        while(n){
            int temp=n%10;//temp为当前处理的十进制位
            n/=10;
            if(temp+m<10) ans=(ans+1)%mod;//如果当前位上的值加上操作次数小于10，则只有1位
            else ans=(ans+len[temp+m-9])%mod;//如果大于等于9，等价于对9操作temp+m-9次操作得到的结果
        }
        cout<<ans<<endl;
    }
}
