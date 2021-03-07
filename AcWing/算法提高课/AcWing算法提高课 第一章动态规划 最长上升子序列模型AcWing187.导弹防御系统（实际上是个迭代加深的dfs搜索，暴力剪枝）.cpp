#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=57;
const double eps=1e-6;
const int mod=1e9+7;

int n,ans;
int num[maxn],up[maxn],down[maxn];

void dfs(int deep,int u,int d){
    if(u+d>=ans) return;
    if(deep==n) {if(u+d<ans) ans=u+d;}
    else{
        int k=0;
        while(k<u&&up[k]>=num[deep]) k++;
        if(k<u){
            int temp=up[k];
            up[k]=num[deep];
            dfs(deep+1,u,d);
            up[k]=temp;
        }
        else{
            up[u++]=num[deep];
            dfs(deep+1,u,d);
            u--;
        }

        k=0;
        while(k<d&&down[k]<=num[deep]) k++;
        if(k<d){
            int temp=down[k];
            down[k]=num[deep];
            dfs(deep+1,u,d);
            down[k]=temp;
        }
        else{
            down[d++]=num[deep];
            dfs(deep+1,u,d);
            d--;
        }
    }
}

int main(){
    IOS
    while(cin>>n,n){
        for(int i=0;i<n;i++) cin>>num[i];
        ans=n;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
}
