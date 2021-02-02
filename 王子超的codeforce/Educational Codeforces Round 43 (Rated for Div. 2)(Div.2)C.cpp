#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=3e5+7;

struct Node//区间结构体，tar标记这是第几个区间，用于输出
{
    int l,r;
    int tar;
};

bool cmp(Node a,Node b)//sort的比较函数，左边界越靠左的排序后越在前，左边界相同情况下，右边界越靠右排序后越在前
{
    if(a.l==b.l) return a.r>b.r;
    else return a.l<b.l;
}

Node node[maxn];
int n;

int main()
{
    IOS
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>node[i].l>>node[i].r;
        node[i].tar=i+1;
    }
    sort(node,node+n,cmp);
    int pre=-1,r=0;//pre记录前面右边界最大的区间是第几个，r标记当前出现的最大右边界
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        if(node[i].r<=r)
        {
            cout<<node[i].tar<<' '<<pre<<endl;
            flag=1;
            break;
        }
        else {pre=node[i].tar;r=node[i].r;}//更新右边界最大的区间以及最大右边界的值
    }
    if(!flag) cout<<-1<<' '<<-1<<endl;
}
