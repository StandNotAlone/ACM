#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
const int mod=1e9+7;

bool num[maxn];
int tot=0,n,q;

int main(){
    IOS
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]) tot++;
    }
    while(q--){
        int ope,x;cin>>ope>>x;
        if(ope==1) {
            tot-=num[x];
            num[x]=!num[x];
            tot+=num[x];
        }
        else if(x>tot) cout<<0<<endl;
        else cout<<1<<endl;
    }
}
