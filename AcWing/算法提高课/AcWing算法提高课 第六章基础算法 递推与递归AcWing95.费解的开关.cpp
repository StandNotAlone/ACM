#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

bool field[10][10],temp[10][10];;

int dir[5][2]={
    0,0,
    0,1,
    0,-1,
    -1,0,
    1,0
};

void change(int a,int b){
    for(int i=0;i<5;i++)
        temp[a+dir[i][0]][b+dir[i][1]]^=1;
}

int main(){
    IOS
    int n;cin>>n;
    while(n--){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                char c;cin>>c;
                field[i][j]=c-'0';
            }
        }
        int ans=10;
        for(int i=0;i<32;i++){//枚举第一行的操作方式
            for(int j=0;j<=6;j++)
                for(int k=0;k<=6;k++)
                    temp[j][k]=field[j][k];
            int cnt=0;
            for(int j=0;j<5;j++){
                if(i>>j&1) {change(1,j+1);cnt++;}
            }
            for(int j=1;j<5;j++)
                for(int k=1;k<=5;k++)
                    if(!temp[j][k]) {change(j+1,k);cnt++;}
            bool flag=1;
            for(int j=1;j<=5;j++) if(!temp[5][j]||!temp[1][j]) flag=0;
            if(flag&&cnt<=6) ans=cnt;
        }
        if(ans<=6) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}
