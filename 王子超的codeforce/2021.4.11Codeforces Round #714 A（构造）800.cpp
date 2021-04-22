#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

bool flag[107];
int num[107];

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int lim=(n-1)/2;
        if(lim<k) cout<<-1<<endl;
        else{
            memset(flag,0,sizeof(flag));//flag[i]标记第i个位置是否被使用
            for(int i=0;i<k;i++){//在下标1,3,5,7....依次放置k个最大的数
                flag[i*2+1]=1;
                num[i*2+1]=n-i;
            }
            int cas=1;
            for(int i=0;i<n;i++){//剩下的数从小到大，从左往右依次放进去
                if(!flag[i]){
                    num[i]=cas++;
                }
            }
            for(int i=0;i<n;i++) cout<<num[i]<<' ';
            cout<<endl;
        }
    }
}
