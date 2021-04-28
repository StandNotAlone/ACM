#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int tree[maxn];
int sp;
int n;

void add(int x,int v){
    for(;x<=n;x+=x&-x) tree[x]+=v;
}

int sum(int x){
    int ret=0;
    for(;x>0;x-=x&-x) ret+=tree[x];
    return ret;
}

void getsp(){
    int temp=n;
    while(temp){
        sp++;
        temp>>=1;
    }
}

int kth(int k){
    int ret=0;
    int sum=0;
    for(int i=sp-1;i>=0;i--){
        ret+=(1<<i);
        if(ret>=n||sum+tree[ret]>=k) ret-=(1<<i);
        else sum+=tree[ret];
    }
    return ret+1;
}

int num[maxn],cas[maxn];

int main(){
    IOS
    cin>>n;
    getsp();
    for(int i=1;i<=n;i++) add(i,1);
    for(int i=2;i<=n;i++) cin>>cas[i];
    for(int i=n;i>0;i--){
        num[i]=kth(cas[i]+1);
        add(num[i],-1);
    }
    for(int i=1;i<=n;i++){
        cout<<num[i]<<endl;
    }
}
