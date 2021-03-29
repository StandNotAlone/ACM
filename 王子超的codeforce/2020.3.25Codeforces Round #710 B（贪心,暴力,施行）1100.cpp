#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n,k;
        string s;
        cin>>n>>k>>s;
        int ans=0;
        int now=-1;//now记录我们当前下标检查到了哪里
        for(int i=0;i<n;i++)
            if(s[i]=='*') {now=i;break;}//找到最左侧的第一个*
        while(1){
            ans++;
            s[now]='x';//当前位置修改为x
            int net=min(now+k,n-1);//net为我们下一个要修改为x的*位置，这里贪心取最远，但是不能超出字符串上限
            while(s[net]=='.') net--;//如果net位置是.则往回退，去找在k长度范围内，且最靠右的*
            if(net==now) break;//如果net最后=now，代表当前已经是最后一个*了，结束循环
            now=net;
        }
        cout<<ans<<endl;
    }
}

