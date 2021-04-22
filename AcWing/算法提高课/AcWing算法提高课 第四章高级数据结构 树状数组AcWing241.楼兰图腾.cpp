#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,num[maxn],tree[maxn];
ll cas[2][maxn];

void add(int tar,int x){
    for(;tar<=n;tar+=tar&-tar) tree[tar]+=x;
}

int ask(int tar){
    int ret=0;
    for(;tar>0;tar-=tar&-tar) ret+=tree[tar];
    return ret;
}

ll ans1,ans2;


int main(){
    IOS
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        cas[0][i]=ask(num[i]-1);
        cas[1][i]=i-ask(num[i]);
        add(num[i],1);
    }
    memset(tree,0,sizeof(tree));
    for(int i=n-1;i>=0;i--){
        int temp=n-i-1-ask(num[i]);
        ans1+=cas[1][i]*temp;
        temp=ask(num[i]-1);
        ans2+=cas[0][i]*temp;
        add(num[i],1);
    }
    cout<<ans1<<' '<<ans2<<endl;
}
