#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool flag[60];

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int pre=-1,ans=0;//pre标记上一段连续1区间的右侧位置
        for(int i=1;i<=n;i++)
        {
            cin>>flag[i];
            if(flag[i]&&!flag[i-1]&&pre!=-1)//记录连续1区间之间的0的个数，pre=-1的时候代表是最左侧的0区间不需要计算进去
            {//flag[i]=1，flag[i-1]为0，正好是连续0区间到连续1区间的分界处
                ans+=i-pre;//两个位置下标相减，即为这一段连续0区间的长度
                pre=-1;
            }
            if(!flag[i]&&flag[i-1]) pre=i;
        }
        cout<<ans<<endl;
    }
}
