#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e2+7;
const double eps=1e-6;
const int mod=1e9+7;

int a[maxn],b[maxn],T[maxn];
int n;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        for(int i=1;i<=n;i++) cin>>T[i];
        int now=0;//now代表当前时间
        for(int i=1;i<n;i++){//这里走到站点n-1即可
            now+=a[i]-b[i-1]+T[i];//从站点i-1到站点i需要划分的时间
            int temp=(b[i]-a[i]+1)/2;//在站点i至少需要等待的时间
            now+=temp;
            if(now<b[i]) now=b[i];//从站点i离开必须到时间b[i]之后
        }
        now+=a[n]-b[n-1]+T[n];//到达站点n就可以立即结束，不需要再多加时间
        cout<<now<<endl;
    }
}
