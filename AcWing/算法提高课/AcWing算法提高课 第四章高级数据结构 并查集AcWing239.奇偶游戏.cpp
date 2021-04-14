#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m,tot;
int ans;
int fa[maxn*4];
unordered_map<int,int>M;

int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}

void merge(int x,int y){fa[get(x)]=get(y);}

int main(){
    IOS
    cin>>n>>m;
    for(int i=0;i<4*m;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        int l,r;string s;cin>>l>>r>>s;
        l--;
        if(M.count(l)==0) M[l]=tot++;
        if(M.count(r)==0) M[r]=tot++;
        l=M[l];r=M[r];
        if(s=="even"){
            if(get(l+2*m)==get(r)) break;
            merge(l+2*m,r+2*m);
            merge(l,r);
        }
        else{
            if(get(l)==get(r)) break;
            merge(l+2*m,r);
            merge(l,r+2*m);
        }
        ans++;
    }
    cout<<ans<<endl;
}
