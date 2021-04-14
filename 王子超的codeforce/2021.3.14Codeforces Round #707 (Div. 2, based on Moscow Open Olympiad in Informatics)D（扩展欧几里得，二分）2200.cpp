#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=5e5+7;
const double eps=1e-6;
const int mod=1e9+7;

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!a&&!b) return -1;
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

ll n,m,k;
ll numa[maxn],numb[maxn];
ll flag[maxn*2];
ll lm;//n和m的最小公倍数
vector<ll>cas;//记录一次lcm的长度内，有哪些下标是字母相同的

ll check(ll x){//单次lcm长度内，第x不匹配数字出现的情况
    if(x==0){//特殊处理恰好整数组lcm长度的情况
        ll ret=lm;
        for(int i=0;i<cas.size();i++){
            if(cas[cas.size()-i-1]==lm-i){
                ret--;
            }
            else break;
        }
        return ret-lm;
    }
    ll l=0,r=(ll)cas.size()-1;//二分查找最后一个匹配的位置，借由此计算出最后多余的长度是多少
    while(l<r){
        int mid=((l+r)>>1)+1;
        if(cas[mid]-mid>=x) r=mid-1;
        else l=mid;
    }
    return x+l;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    ll x,y;
    ll g=exgcd(n,m,x,y);//n和m的最大公约数，并计算出x*n+y*m=g的一组特解x,y
    lm=n/g*m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&numa[i]);
        flag[numa[i]]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&numb[i]);
        if(flag[numb[i]]&&flag[numb[i]]%g==i%g){//需要满足字母相同，且对最大公约数取模后的值相等，才可能存在满足x*n+y*m=距离的解
            if(flag[numb[i]]==i) cas.push_back(i);
            else{
                //ll tempx=x*(i-flag[numb[i]])/g;
                ll tempy=y*((i-flag[numb[i]])/g)%lm;//求出当前情况对应的特解
                ll tar=-tempy*m+i;//计算下标位置，下标应该在1-lcm之内，因此下面对其值进行处理
                if(tar<0){
                    tar+=((-tar)/lm+1)*lm;
                }
                tar%=lm;
                if(tar==0) tar=lm;
                cas.push_back(tar);
            }
        }
    }
    cas.push_back(0);
    sort(cas.begin(),cas.end());
    ll ans=k/(lm-(ll)cas.size()+1)*lm;//取多少整数组长度的lcm
    k-=k/(lm-(ll)cas.size()+1)*(lm-(ll)cas.size()+1);//剩余还需要几次不相同
    printf("%lld\n",ans+check(k));
}
