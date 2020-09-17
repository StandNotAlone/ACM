#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n,q;
set<ll>S;//集合S用于存储当前有哪些位置上有垃圾，用于计算实现下面两个优先队列的当前线段和待删除线段
priority_queue<ll>length_now,length_delete;
//两个优先队列，now存储当前的图上所有的相邻点之间的线段长度，delete为插入和删除点过程中产生的待删除线段

//由于我们只关注所有点的最左侧和最右侧的距离（set可计算），以及相邻点之间的线段长度中的最大值（优先队列的top()可以获得）

void insert(ll x)//增加点操作
{
    if(S.size())//增加点可能会造成线段的增加和减少
    {
        auto now=S.lower_bound(x);//用lower_bound找到集合S中大于x的第一个位置
        if(now==S.begin()) length_now.push(*now-x);//如果大于x的第一个位置就是最小的点了，那加入的点是在目前的最左侧，只增加了*now-x这一条线段
        else//如果大于x的第一个位置不是最小的点
        {
            if(now==S.end())//如果大于x的第一个位置是集合的末尾，代表加入的点在最右侧，对now--操作变成之前最大点的位置，只增加了x-*now这一条线段
            {
                now--;
                length_now.push(x-*now);
            }
            else//如果不是末尾，则代表新加入的点是在两个点的中间
            {
                ll temp=*now;//用temp临时记录右侧点的值，再对now--变为左侧点的位置
                now--;
                length_now.push(temp-x);//新增加了两条线段，分别与左右侧相邻点构成
                length_now.push(x-*now);
                length_delete.push(temp-*now);//原本左右侧相邻点构成的线段被删除
            }
        }
    }
    S.insert(x);
}

void erase(ll x)//同insert操作的思路
{
    S.erase(x);
    if(S.size())
    {
        auto now=S.lower_bound(x);
        if(now==S.begin()) length_delete.push(*now-x);
        else
        {
            if(now!=S.end())
            {
                ll temp=*now;
                now--;
                length_now.push(temp-*now);
                length_delete.push(temp-x);
                length_delete.push(x-*now);
            }
            else
            {
                now--;
                length_delete.push(x-*now);
            }
        }
    }
}

void out()
{
    if(S.size()==0) cout<<0<<endl;//这里要特判一下集合S是否为空，否则下面的rbegin()-begin()的操作会出错
    else
    {
        while(length_delete.size()&&length_delete.top()==length_now.top())//我们只关注所有线段中最大的值，因此用优先队列存储即可
        {//把待删除的最大线段依次删去即可
            length_delete.pop();
            length_now.pop();
        }
        ll ans=*S.rbegin()-*S.begin();
        if(length_now.size()) cout<<ans-length_now.top()<<endl;
        else cout<<0<<endl;
    }
}

int32_t main()
{
    IOS;
    cin>>n>>q;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        insert(x);
    }
    out();
    for(ll i=0;i<q;i++)
    {
        ll ope,x;
        cin>>ope>>x;
        if(ope) insert(x);
        else erase(x);
        out();
    }
}
