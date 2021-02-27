#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=3e2+7;
const double eps=1e-6;
const int mod=1e9+7;

int r,c;
int field[maxn][maxn];
int num[maxn][maxn];
int dir[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};

int dp(int x,int y){
    if(num[x][y]) return num[x][y];
    for(int i=0;i<4;i++){
        int tempx=x+dir[i][0];
        int tempy=y+dir[i][1];
        if(tempx>=1&&tempx<=r&&tempy>=1&&tempy<=c&&field[tempx][tempy]<field[x][y])
            num[x][y]=max(num[x][y],dp(tempx,tempy));
    }
    num[x][y]++;
    return num[x][y];
}

int main(){
    IOS
    cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>field[i][j];
    int ans=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            ans=max(ans,dp(i,j));
    cout<<ans<<endl;
}
