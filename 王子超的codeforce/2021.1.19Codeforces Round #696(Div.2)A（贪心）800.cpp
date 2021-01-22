#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string a;cin>>a;
        int pre=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=2;j>=0;j--)//j代表当前位a+b的和c，从大到小枚举
            {
                if(j!=pre&&j-a[i]+'0'<=1)//需要满足不与上一位的值相等，
                {
                    cout<<j+'0'-a[i];//j+'0'变为对应字符类型，与a[i]相减得到b[i]对应的整数值
                    pre=j;//记录上一位的和为多少
                    break;
                }
            }
        }
        cout<<endl;
    }
}
