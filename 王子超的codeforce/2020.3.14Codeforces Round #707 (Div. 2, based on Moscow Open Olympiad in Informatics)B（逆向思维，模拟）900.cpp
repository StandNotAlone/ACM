#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int a[maxn];
bool flag[maxn];//flag标记是否被染色

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];

        int now=0;//now记录从当前位置向下有多少层会被染色
        for(int i=n-1;i>=0;i--){
            now=max(now,a[i]);//更新更大的now值
            if(now) {flag[i]=1;now--;}//如果now不为0，将当前层染色
        }

        for(int i=0;i<n;i++){
            cout<<flag[i]<<' ';
            flag[i]=0;
        }
        cout<<endl;
    }
}
