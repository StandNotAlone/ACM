#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int num[maxn];
ll tree[maxn];
int n,m;

void add(int x,ll v){
    for(;x<=n;x+=x&-x) tree[x]+=v;
}

ll sum(int x){
    ll ret=0;
    for(;x>0;x-=x&-x) ret+=tree[x];
    return ret;
}

int main(){
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        add(i,num[i]-num[i-1]);
    }
    while(m--){
        char c;cin>>c;
        if(c=='Q'){
            int x;cin>>x;
            cout<<sum(x)<<endl;
        }
        else{
            int l,r,v;cin>>l>>r>>v;
            add(l,v);
            add(r+1,-v);
        }
    }
}
