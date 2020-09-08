#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        ll ans=0;
        ll temp=0;//temp记录我们当前位置左侧还有多少的正数可用
        for(int i=0;i<n;i++)
        {
            temp+=num[i];//下面的if运算保证了temp一定不是负数
            //temp与当前位置上的数字进行加法运算，如果num[i]是负数则正是题意中无消耗的操作
            if(temp<0)//如果出现了无法被无消耗操作除去的负数部分,则必然要与后面的正数进行有消耗的操作
                //此处累加temp的绝对值到答案上，并清零
            {
                ans-=temp;
                temp=0;
            }
        }
        if(temp<0) ans-=temp;
        cout<<ans<<endl;
    }
}
