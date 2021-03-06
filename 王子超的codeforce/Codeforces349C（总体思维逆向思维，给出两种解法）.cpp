第一种解法（第二种更直接一点，不想看第一种就去看第二种）
我们可以这样想，如果我们总共进行了x轮游戏，如果一个人在其中的k轮被选为上帝，那么实际上他作为玩家的轮数为x-k，也就是说他期望游玩的轮数num要满足num<=x-k，也就是num+k<=x。
注意观察到这里的k实际上一个需要参加游戏轮数的增加值（不管是当上帝还是玩家），总共进行x轮游戏也就有x人次当了上帝，也就是说总共要增加x轮数到他们的期望值上，我们所求的答案是增加总共x轮数到他们原本的期望轮数后，所有轮数中最大值的最小值。（这么明显的一个二分答案特点）
由此这个问题可以转化为一种二分答案的思路。但是这里的第一种解法采取的是结论解法。

我们把初始期望轮数中的最大值定位Max，我们根据最终答案轮数ans=Max（轮数不可能比期望轮数最大值Max还小的，原因自己想）还是ans>Max分为两种情况讨论。

我们计算每一个人的期望轮数与最大值Max的差值，累加到temp上，也就是ans=Max情况下玩家可以作为上帝最多次数，实际上也就是游戏进行的最多轮数。如果temp大于等于Max轮，就代表是可以满足进行Max轮的需求的，ans就是Max。
但是如果Max>temp的话，代表还存在Max-temp轮数的上帝没人分配走，那么这些次数还要继续分配给所有人，我们希望最后的最大轮数尽可能小的话，那就采取尽肯能平均分配的方法。
其中n个人当中的一个被选做了最大轮数，那么实际上我们Max-temp平均分配到了n-1个人当中，答案ans=Max+[(Max-temp)/n-1]（这里要向上取整）
#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=1e5+7;

ll num[maxn];

int main()
{
� � IOS;
� � ll n;
� � cin>>n;
� � for(ll i=0;i<n;i++) cin>>num[i];
� � sort(num,num+n);
� � ll temp=0;
� � for(ll i=0;i<n;i++) temp+=num[n-1]-num[i];
� � if(temp>=num[n-1]) cout<<num[n-1]<<endl;
� � else
� � {
� � � � temp=num[n-1]-temp;
� � � � ll ans=num[n-1]+temp/(n-1);
� � � � if(temp%(n-1)) ans++;
� � � � cout<<ans<<endl;
� � }
}



第二种解法
我们每次进行游戏，可以令n-1个人还需要进行的轮数-1,也就是所有人的总需要轮数-(n-1)。
那么我们统计所有人的总需要轮数sum，在最优策略下（每次都选取当前需要轮数最小的那个人当上帝）需要进行的轮数为[sum/(n-1)]（向上取整），实际上这种情况就契合了第一种解法中讨论的ans>Max（Max为初始期望轮数中的最大值）的情况。
如果[sum/(n-1)]<Max的话，由于ans不可能小于Max（这个自己想），答案只能为Max。（契合了第一种解法中ans=Max的情况）

#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
� � IOS;
� � ll n;
� � cin>>n;
� � ll sum=0,Max=-1;
� � for(ll i=0;i<n;i++)
� � {
� � � � ll x;
� � � � cin>>x;
� � � � sum+=x;
� � � � Max=max(Max,x);
� � }
� � cout<<max(Max,sum/(n-1)+(sum%(n-1)?1:0))<<endl;
}
