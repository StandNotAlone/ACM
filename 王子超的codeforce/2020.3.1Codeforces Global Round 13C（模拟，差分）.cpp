#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=5e3+7;
const double eps=1e-6;
const int mod=1e9+7;

int num[maxn];
int flag[maxn];//差分数组

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        memset(flag,0,sizeof(flag));
        int n;cin>>n;
        ll ans=0,now=0;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            now+=flag[i];
            if(num[i]>1){
                flag[i+2]++;
                if(i+num[i]+1<=n) flag[i+num[i]+1]--;
            }
            if(now>num[i]-1){
                flag[i+1]+=now-num[i]+1;
                flag[i+2]-=now-num[i]+1;
            }
            num[i]-=now;
            ans+=max(0,num[i]-1);
        }
        cout<<ans<<endl;
    }
}
