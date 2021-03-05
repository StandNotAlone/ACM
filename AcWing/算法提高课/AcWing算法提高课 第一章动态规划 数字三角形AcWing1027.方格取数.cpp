#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=17;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int dp[maxn<<1][maxn][maxn];
int field[maxn][maxn];

int main(){
    IOS
    cin>>n;
    int a,b,c;
    while(cin>>a>>b>>c,a||b||c) field[a][b]=c;
    dp[2][1][1]=field[1][1];
    for(int k=3;k<=n*2;k++){
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++){
                int temp=max(dp[k-1][i][j],dp[k-1][i-1][j-1]);
                temp=max(temp,dp[k-1][i][j-1]);
                temp=max(temp,dp[k-1][i-1][j]);
                if(i==j) dp[k][i][j]=temp+field[i][k-i];
                else dp[k][i][j]=temp+field[i][k-i]+field[j][k-j];
            }
    }
    cout<<dp[n<<1][n][n]<<endl;
}

作者：standnotalone
链接：https://www.acwing.com/activity/content/code/content/942744/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。