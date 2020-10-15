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
        int len;
        string s;
        cin>>len>>s;
        int need=0,tar=0,ans=0;//need指示当前位置后面需要删除多少个，tar为当前位置
        while(1)
        {
            ans++;
            int net=tar;
            while(net+1<len&&s[net+1]==s[tar]) net++;//找相同字符的前缀最右侧下标
            need++;//我们当前位置往后的地方在本次操作要再删一个数
            need=max(0,need-(net-tar));//当前前缀长度-1的数字，可以在前面的操作和当前的操作中贪心删掉
            if(len-net-1<=need||net==len-1) break;//剩余的部分如果比前面操作需要删除的数量多，或者已经扫到末尾了结束循环
            tar=net+1;
        }
        cout<<ans<<endl;
    }
}
