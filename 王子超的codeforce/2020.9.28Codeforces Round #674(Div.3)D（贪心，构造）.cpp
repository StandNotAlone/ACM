#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    ll n,sum=0,ans=0;
    cin>>n;
    map<ll,bool>M;//M[x]记录前缀合x是否在前面出现过，如果当前前缀和为x，那么在当前位置到之前记录x的位置之间的数加起来为0
    M[0]=1;//0要初始化为出现过，意思为开头到目前为止所有部分的值加起来为0
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        sum+=x;
        if(M.find(sum)!=M.end())//如果当前前缀和和之前某个位置的相同，代表这两个位置间（包括当前位置）的值加起来为0
        {//贪心过程在当前位置前的一个位置赛入一个绝对值足够大的数字即可
            M.clear();
            sum=x;//当前前缀合变为刚读入的这个数，前面的数字不再对后续产生影响，可以理解为我们在前面一个位置插入了一个无穷大
            M[x]=M[0]=1;
            ans++;
        }
        else M[sum]=1;
    }
    cout<<ans<<endl;
}
