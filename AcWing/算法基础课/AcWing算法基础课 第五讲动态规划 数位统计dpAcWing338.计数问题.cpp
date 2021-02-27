#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int power(int x)
{
    int ret=1;
    while(x--) ret*=10;
    return ret;
}

int get(vector<int>&num,int l,int r)
{
    int ret=0;
    for(int i=r;i>=l;i--) ret=ret*10+num[i];
    return ret;
}

ll count(int x,int d)
{
    if(x<0) return 0;
    ll ret=0;
    vector<int>num;
    while(x)
    {
        num.push_back(x%10);
        x/=10;
    }

    for(int i=(int)num.size()-1-!d;i>=0;i--)
    {
        ret+=get(num,i+1,(int)num.size()-1)*power(i);
        if(!d) ret-=power(i);
        if(num[i]>d) ret+=power(i);
        if(num[i]==d) ret+=get(num,0,i)-power(i)*d+1;
    }

    return ret;
}

int main()
{
    IOS
    int a,b;;
    while(cin>>a>>b,a||b)
    {
        if(a>b) swap(a,b);
        for(int i=0;i<10;i++)
            cout<<count(b,i)-count(a-1,i)<<' ';
        cout<<endl;
    }
}
