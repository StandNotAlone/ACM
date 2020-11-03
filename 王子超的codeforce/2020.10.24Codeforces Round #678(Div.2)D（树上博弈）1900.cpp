#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;

int p[maxn];//由于题目说了p[i]的值必定小于i，图是经过排序后给定边的，因此直接用一个一维数组即可存图
ll a[maxn];
int son[maxn];//son[i]记录结点i的子树有多少叶子结点

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) son[i]=1;
    for(int i=2;i<=n;i++) {cin>>p[i];son[p[i]]=0;}
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=n;i;i--)//反向从叶子结点"递归"回来
    {
        ans=max(ans,a[i]/son[i]+(a[i]%son[i]?1:0));//当前位置以及其子树上所有的所有人，我们按照尽可能平均的原则分配到各个叶子结点的方向上去
        //如果某一个方向的人数特别多或者特别少，当前结点的位置人数较少，会无法在当前结点上实现平均分配到各个叶子结点方向上去
        //但是此时怪物必然是选择人多的那个方向去了，并且我们这时候不会将当前结点的人分配到这个人多的方向去，否则就是可以平均分配的情况了,也就是说当前位置的人数不会影响该方向子树的总人数（重要）
        //此时我们计算人多的那个方向子树的平均分配方案，可以得到该方向上的最优结果
        //这里运用了递归的思想，但是由于给定数据是排序后的特别数据，反向for循环即可实现
        a[p[i]]+=a[i];
        son[p[i]]+=son[i];
    }
    cout<<ans<<endl;
}
