#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

ll num[maxn];
ll tree1[maxn],tree2[maxn];
int n,m;

void add(ll t[],int x,ll v){
    for(;x<=n;x+=x&-x) t[x]+=v;
}

ll sum(ll t[],int x){
    ll ret=0;
    for(;x>0;x-=x&-x) ret+=t[x];
    return ret;
}

int main(){
    IOS
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        add(tree1,i,num[i]-num[i-1]);
        add(tree2,i,i*(num[i]-num[i-1]));
    }
    while(m--){
        char c;cin>>c;
        if(c=='Q'){
            int l,r;cin>>l>>r;
            cout<<(sum(tree1,r)*(r+1)-sum(tree2,r))-(sum(tree1,l-1)*(l)-sum(tree2,l-1))<<endl;
        }
        else{
            int l,r,v;cin>>l>>r>>v;
            add(tree1,l,v);
            add(tree1,r+1,-v);
            add(tree2,l,v*l);
            add(tree2,r+1,-v*(r+1));
        }
    }
}
