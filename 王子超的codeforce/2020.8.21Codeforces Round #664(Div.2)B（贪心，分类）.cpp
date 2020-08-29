#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        ll a1,b1,c1,a2,b2,c2;
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        ll ans=0;
        ll temp=min(c1,b2);//考虑我们增加的2*1的对数最多有多少
        ans+=temp*2;c1-=temp;//累加到答案上，并且减去使用掉的第一个数列中的2的个数
        temp=max(0ll,c2-c1-a1);//考虑减少的1*2的对数最少有多少
        //我们尽可能让第二个数列的2与第一个数列的2或者0配对，剩下的无可奈何只能与1配对
        //这里要和0取个max，因为c2-c1-a1可能为负数。
        ans-=2*temp;
        cout<<ans<<endl;
    }
}