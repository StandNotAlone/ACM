#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct Node
{
    int a,b;
};

int n;
vector<Node>node;

void qsort_bushi(int l,int r)//类似快排的递归写法，对长度为2的整数次幂的部分进行区间合并，左边的一半和右边的一半一一对应进行操作
{
    if(l==r) return;
    int mid=(l+r)>>1;
    qsort_bushi(l,mid);
    qsort_bushi(mid+1,r);
    while(l<r) node.push_back({l++,r--});
}

int32_t main()
{
    IOS;
    cin>>n;
    int temp=1;
    while(temp*2<n) temp<<=1;//寻找一个最小的2的整数次幂，其两段区间可以覆盖整个n的长度
    qsort_bushi(1,temp);//进行一次操作后1到temp的区间都变成了相同的数字
    qsort_bushi(n-temp+1,n);//进行一次操作后n-temp+1到n的区间都变成了相同的数字
    cout<<node.size()<<endl;
    for(int i=0;i<node.size();i++) cout<<node[i].a<<' '<<node[i].b<<endl;
}
