#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define llINF 9223372036854775807
const ll maxn=1e5+7;

struct Node
{
    ll data,tar;
};

ll n,Min;//Min为数列中的最小值
vector<Node>node;

bool cmp(Node a,Node b)//数值为第一排序关键字，数值相等时按照原下标从小到大排序
//即一个稳定的快速排序
{
    if(a.data!=b.data) return a.data<b.data;
    else return a.tar<b.tar;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        node.resize(n);
        Min=llINF;
        for(ll i=0;i<n;i++)
        {
            cin>>node[i].data;
            node[i].tar=i;
            Min=min(node[i].data,Min);
        }
        sort(node.begin(),node.end(),cmp);
        bool flag=1;
        for(ll i=0;i<n;i++)
        {
            if(node[i].data%Min&&i!=node[i].tar) flag=0;
            //如果当前的数值无法整除Min那代表它是无法被交换位置的
            //如果在稳定排序后的位置与其原位置不同，那么代表我们是无法得到稳定排序后的数列的
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        node.clear();
    }
}