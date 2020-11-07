#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e5+7;

int num[maxn];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int M=0;//所有初始值中的最大值
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            M=max(M,num[i]);
        }
        int tar=-1;//寻找答案位置
        for(int i=1;i<=n;i++)
        {
            if(num[i]==M)//值要与初始最大值相同
            {
                if(i>1&&num[i-1]!=M) tar=i;//与左侧或者右侧的值不同的位置，均满足要求，输出任意一个
                if(i+1<=n&&num[i+1]!=M) tar=i;
            }
        }
        cout<<tar<<endl;
    }
}
