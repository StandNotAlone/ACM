#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

void get(ll now,ll &x,ll &y,ll M){
    if(M==1){x=y=1;return;}
    else{
        ll tempx,tempy;
        ll cas=now/(M/4)+(now%(M/4)?1:0);
        now-=(cas-1)*(M/4);
        get(now,tempx,tempy,M/4);
        switch(cas){
            case 1:x=tempy;y=tempx;break;
            case 2:x=tempx;y=tempy+sqrt(M)/2;break;
            case 3:x=tempx+sqrt(M)/2;y=tempy+sqrt(M)/2;break;
            case 4:x=sqrt(M)+1-tempy;y=sqrt(M)/2+1-tempx;break;
            default:break;
        }
    }
}

int main(){
    int n;scanf("%d",&n);
    while(n--){
        ll N,a,b;scanf("%lld%lld%lld",&N,&a,&b);
        ll M=1;
        for(int i=0;i<N;i++) M*=4;
        ll x[2],y[2];
        get(a,x[0],y[0],M);
        get(b,x[1],y[1],M);
        x[0]-=x[1];y[0]-=y[1];
        printf("%.0lf\n",sqrt(x[0]*x[0]+y[0]*y[0])*10);
    }
}
