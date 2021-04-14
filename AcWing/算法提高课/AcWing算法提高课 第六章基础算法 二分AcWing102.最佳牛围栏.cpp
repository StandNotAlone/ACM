#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,f;
double num[100007];
double pre[100007];

bool check(double x){
    bool flag=0;
    double p=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+num[i]-x;
        if(i>=f){
            if(pre[i]>p) {flag=1;break;}
            p=min(p,pre[i-f+1]);
        }
    }
    return flag;
}

int main(){
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;i++) scanf("%lf",&num[i]);
    double l=1,r=2000;
    while(l+eps<r){
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.0lf\n",floor(r*1000));
}
