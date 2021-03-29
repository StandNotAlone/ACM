#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int num[maxn];

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num,num+n);
        int M=0;//统计出现次数最多的数字出现了几次
        for(int i=0;i<n;i++){
            int cnt=1;
            while(i+1<n&&num[i+1]==num[i]) {i++;cnt++;}//统计当前这个数出现了几次
            M=max(M,cnt);
        }
        if(M*2>=n) cout<<M*2-n<<endl;//如果大于等于总个数的一半，答案就是M-(n-M)
        else cout<<n%2<<endl;//反之必定存在方案可以清除整个数组，除非n为奇数由于每次删除两个会剩下一个
    }
}
