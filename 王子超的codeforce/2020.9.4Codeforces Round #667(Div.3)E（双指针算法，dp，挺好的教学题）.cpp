#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;

ll node[maxn];//记录点的横坐标数据，按照x的增序进行排序
ll n,k,temp;
ll len[maxn];//len[i]记录node数组中第i个点作为长度为k的挡板的右端点，该挡板可以挡住多少点，用于后面的dp过程

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>node[i];
        for(int i=0;i<n;i++) cin>>temp;
        sort(node,node+n);
        ll tarl,tarr;//tarr指示我们当前挡板的右端点是node数组中的哪一个点，tarl指示当前挡板左端点是node数组中的哪一个点
        ll ans=0,Max=0;//ans为我们最后的答案，两块挡板能挡住的最多点数。Max记录对于tarl左侧的点，一块长度为k的挡板能挡住的最多点数，用于dp过程。
        for(tarr=tarl=0;tarr<n;tarr++)
        {
            while(node[tarl]<node[tarr]-k)//左端点与右端点的横坐标需要满足条件差值不超过k
            {
                Max=max(Max,len[tarl]);//dp过程，tarl需要右移，此时要更新Max记录的值
                tarl++;
            }
            len[tarr]=tarr-tarl+1;//计算len[tarr]，为node数组中第tarr个点作为长度为k的挡板的右端点，该挡板可以挡住的点的数量
            ans=max(Max+len[tarr],ans);//更新ans值，Max为tarl左侧的那块挡板挡住的点数，len[tarr]为当前挡板挡住的点数，两者相加即为当前情况的最优值
        }
//        for(tarr=tarl=0;tarr<n;tarr++)
//        {
//            while(node[tarl]<node[tarr]-k) tarl++;
//            len[tarr]=tarr-tarl+1;
//        }
//        for(tarr=tarl=0;tarr<n;tarr++)
//        {
//            while(node[tarl]<node[tarr]-k) {Max=max(Max,len[tarl]);tarl++;}
//            ans=max(Max+len[tarr],ans);
//        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++) len[i]=0;
    }
}