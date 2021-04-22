#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

ll n,p;
ll a[maxn];
bool flag[maxn];
struct Node{
    ll num;
    int tar;
};

vector<Node>node;

bool cmp(Node a,Node b){
    return a.num<b.num;
}

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        cin>>n>>p;
        node.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            flag[i]=0;
            node.push_back({a[i],i});
        }
        sort(node.begin(),node.end(),cmp);
        ll ans=(n-1)*p;//只选择第2种边得到的权值
        for(int i=0;i<n;i++){
            if(node[i].num>=p) break;//如果当前的值已经不比p小了，已经没有继续执行的意义
            if(flag[node[i].tar]) continue;//如果当前的值已经被扫过，则跳过
            int l=node[i].tar,r=l;//左右边界
            flag[l]=1;
            while(l>1&&!flag[l-1]&&a[l-1]%node[i].num==0) flag[l--]=1;//左右边界取尽可能大
            while(r<n&&!flag[r+1]&&a[r+1]%node[i].num==0) flag[r++]=1;
            ans-=(r-l)*(p-node[i].num);//取边后能减少的权值
        }
        cout<<ans<<endl;
    }
}
