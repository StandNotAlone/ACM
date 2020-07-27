#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=3e5+7;

ll n,k,l;
ll deep[maxn];
ll prel,prer;//记录上一个地点可出现的时间区间的左右下标
ll nowl,nowr;//当前位置的可出现的时间区间的左右下标
bool flagl,flagr;//记录pre区间整体右移1个位置后，最左侧和除了最左侧外是否存在区间

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>l;
        for(ll i=1;i<=n;i++) cin>>deep[i];
        prel=0;prer=2*k-1;//初始地点任意时间点都可出现
        bool flag=1;
        for(ll i=1;i<=n;i++)
        {
            ll temp=l-deep[i];//记录当前位置水深最多能增加多少
            if(temp<0)
            {
                flag=0;
                break;
            }
            nowr=min(k-1+temp,2*k-1);//只考虑水深的情况下左右下标的界限是多少
            nowl=max(0ll,k-1-temp);//注意这里对应的水深是[k-1,k-2....1,0,1,2...k-1,k]
            prel++;prer++;//前一个位置时间区间整体+1
            if(prel==2*k)//特判，如果左下标超出了限制，代表只有一个时间点2k-1且右移后变成了0
            {
                flagr=0;
                flagl=1;//由于只右移一个位置，因此flagl指示的最左侧区间只有一个0时间点
            }
            else if(prer==2*k)//右下标超出了限制而左下标没有，则最左侧存在区间，除了最左侧外也有区间
            {
                prer--;
                flagl=flagr=1;
            }
            else//左右下标都未超出界限
            {
                flagl=0;
                flagr=1;
            }
            if(flagl&&nowl==0);//存在左时间区间并且当前时间区间为0的时候就不要做修改了
            else//左侧区间考虑完毕，再考虑右侧区间
            {
                if(flagr)//存在右区间的情况
                {
                    if(nowl>prer||nowr<prel)//前面位置的区间与当前区间没有匹配部分，那就没有方案了
                    {
                        flag=0;
                        break;
                    }
                    else nowl=max(nowl,prel);//由于我们可以原地停留，因此更新区间左下标就可以了
                }
                else//如果没有右侧区间那就是没有可行方案了
                {
                    flag=0;
                    break;
                }
            }
            prel=nowl;
            prer=nowr;
            if(prer==2*k-1) prel=0;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}


