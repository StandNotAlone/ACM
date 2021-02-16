#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

ll num[2*maxn];
ll now=0;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;n*=2;
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num,num+n);
        bool flag=1;
        int now=0;
        for(int i=1;i<n;i+=2)
        {
            if(num[i]!=num[i-1]) flag=0;//需要对应相等
            num[now++]=num[i];//只需要保留一半的数就够了
        }
        ll sum=0;//记录不计算 x轴正轴上，从左往右看(下面的点都这么看)的第1个点，在不计算自身到原点这段距离的情况下其他点产生的距离和
        for(int i=1;i<now;i++)//now即n/2，最开始的n值
        {
            ll mod=i*2;//从第i个点移动到第i+1个点，每移动一个长度会增加2i的总距离
            ll dis=num[i]-num[i-1];
            if(dis==0||dis%mod) {flag=0;break;}//如果无法整除增加的长度或者点重合了都是不满足的情况
            else sum+=dis/mod*2*(now-i);//当前这一段会被计算2*(now-i)次
        }
        sum=num[0]-sum;//依靠剩余的sum值计算第一个点和原点的距离
        if(sum%n||sum<n) flag=0;//该距离会被计算2n(这里的n在最开始已经*2了)次，因此要被2n整除且距离不为0
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
