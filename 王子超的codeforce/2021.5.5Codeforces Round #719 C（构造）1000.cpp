#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int field[107][107];

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==2) {cout<<-1<<endl;continue;}
        int now=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if((i+j)%2==0) field[i][j]=now++;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if((i+j)%2==1) field[i][j]=now++;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j>1) cout<<' ';
                cout<<field[i][j];
            }
            cout<<endl;
        }
    }
}
