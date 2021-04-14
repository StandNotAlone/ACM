#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int field[5007][5007];
int n,r;

int main(){
    IOS
    cin>>n>>r;
    while(n--){
        int x,y,w;
        cin>>x>>y>>w;
        field[x+1][y+1]+=w;
    }
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            field[i][j]+=field[i-1][j]+field[i][j-1]-field[i-1][j-1];
    int ans=0;
    for(int i=0;1;i++){
        for(int j=0;1;j++){
            int x=min(5000,i+r-1),y=min(5000,j+r-1);
            ans=max(ans,field[x+1][y+1]-field[i][y+1]-field[x+1][j]+field[i][j]);
            if(j+r>5000) break;
        }
        if(i+r>5000) break;
    }
    cout<<ans<<endl;
}
