#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e5+7;

ll num[maxn];
ll n,q;

ll check(ll i)//返回下标i的位置是波峰还是波谷，决定了这个位置上的数字是增加还是减少到最终结果上
//1代表波峰，-1代表波谷，0代表其他情况，恰好对应了其累加到结果上对应的系数
{
    if(n==1) return 1;//特判数列只有1个数的情况
    if(i==1)//如果当前位置是开头位置，如果是波峰的话就累加到结果上，其他情况都不取（开头的波谷不取）
    {
        if(num[1]>num[2]) return 1;//此时判断右侧即可
        else return 0;
    }
    if(i==n)//如果当前位置是末尾位置，如果是波峰的话就累加到结果上，其他情况都不取（末尾的波谷不取）
    {
        if(num[i]>num[i-1]) return 1;//此时判断左侧即可
        else return 0;
    }
    if(num[i]>num[i-1]&&num[i]>num[i+1]) return 1;//其他情况下如果既大于左边又大于右边则为波峰
    if(num[i]<num[i-1]&&num[i]<num[i+1]) return -1;//其他情况下入股既小于左右又小于右边则为波谷
    return 0;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(ll i=1;i<=n;i++) cin>>num[i];
        ll ans=0;
        for(ll i=1;i<=n;i++)//直接for一遍，每个数乘以其check对应的系数累加到结果上即可
        {
            ans+=check(i)*num[i];
        }
        cout<<ans<<endl;
        for(ll i=0;i<q;i++)//q次调换num[l]和num[r]
        {
            ll l,r;
            cin>>l>>r;
            if(l!=r)//l=r的情况直接跳过
            {
                if(l>1) ans-=check(l-1)*num[l-1];//l-1的位置如果存在，做逆运算
                if(l<n&&l+1!=r) ans-=check(l+1)*num[l+1];//l+1的位置如果存在，也做逆运算
                //下面同样的对r-1,r+1,l,r四个位置做逆运算
                if(r>1&&r-1>l+1) ans-=check(r-1)*num[r-1];//此处要注意特判r-1的位置与l+1不重合，否则会重复运算，l和r差值小于2的情况下都会有重合
                if(r<n) ans-=check(r+1)*num[r+1];
                ans-=check(l)*num[l];
                ans-=check(r)*num[r];
                swap(num[l],num[r]);//交换后把对应受影响位置的值加回来
                if(l>1) ans+=check(l-1)*num[l-1];
                if(l<n&&l+1!=r) ans+=check(l+1)*num[l+1];
                if(r>1&&r-1>l+1) ans+=check(r-1)*num[r-1];
                if(r<n) ans+=check(r+1)*num[r+1];
                ans+=check(l)*num[l];
                ans+=check(r)*num[r];
            }
            cout<<ans<<endl;
        }
    }
}
