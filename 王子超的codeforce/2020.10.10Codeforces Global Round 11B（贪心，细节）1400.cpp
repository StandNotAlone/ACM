#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
            {
                ans++;
                if(i&&s[i-1]=='W') ans++;
            }
        }
        vector<int>mid;//存储所有的在连续W区间内的连续L区间的长度，用于贪心排序过程
        int liangbian=0;//存储不在连续W区间内的连续L区间的总长度，也就是从整个字符串左侧和右侧开始看的连续L的个数和
        int l=0,r=n-1;
        while(l<n&&s[l]=='L') {l++;liangbian++;}//左侧的连续L
        while(r>l&&s[r]=='L') {r--;liangbian++;}//右侧的连续L
        for(;l<r;l++)
        {
            if(s[l]=='L')
            {
                int temp=0;
                while(l<r&&s[l]=='L') {l++;temp++;}
                mid.push_back(temp);
            }
        }
        sort(mid.begin(),mid.end());
        for(int i=0;i<mid.size();i++)//优先更改在连续W区间内的连续L区间
        {
            if(k<=0) break;
            ans+=min(k,mid[i])*2;//每次更改都能+2积分
            if(k>=mid[i]) ans++;//如果把当前这一整段L都更改为胜利的话，那么连续W区间个数-1，也就是作为开头胜利的场次-1，会使得最后积分+1
            k-=mid[i];
        }
        if(k>0)
        {
            ans+=min(k,liangbian)*2;
            if(liangbian==n) ans--;//特判一下一开始没有任何1的情况，我们的第一次构造只能+1而不是+2分，因此要-1
        }
        cout<<ans<<endl;
    }
}
