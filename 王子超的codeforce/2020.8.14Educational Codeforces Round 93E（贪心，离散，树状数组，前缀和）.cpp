#include<bits/stdc++.h>/Users/wangzichao/Documents/wzc/wzc.xcodeproj
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll maxn=2e5+7;

vector<ll>origin;//离散化数组和函数
ll find(ll x)
{
    return lower_bound(origin.begin(),origin.end(),x)-origin.begin();
}

//树状数组tree[x]，记录离散化下标小于x的数出现了几个
ll tree[maxn],sp;
void addtree(ll x,ll v)
{
    for(;x<maxn;x+=x&-x) tree[x]+=v;
}

ll sumtree(ll x)
{
    ll ret=0;
    for(;x>0;x-=x&-x) ret+=tree[x];
    return ret;
}

void getsp()
{
    ll temp=maxn-1;
    while(temp)
    {
        temp>>=1;
        sp++;
    }
}

ll kth(ll k)//tree数组中第k小的数是哪个
{
    ll ret=0,sum=0;
    for(ll i=sp-1;i>=0;i--)
    {
        ret+=(1<<i);
        if(ret>=maxn||sum+tree[ret]>=k) ret-=(1<<i);
        else sum+=tree[ret];
    }
    return ret+1;
}

//树状数组treesum[x]，记录离散化下标小于x的数的值的前缀和是多少
ll treesum[maxn];
void addtreesum(ll x,ll v)
{
    for(;x<maxn;x+=x&-x) treesum[x]+=v;
}

ll sumtreesum(ll x)
{
    ll ret=0;
    for(;x>0;x-=x&-x) ret+=treesum[x];
    return ret;
}


ll n;
ll ask[maxn][2];//离线记录一下n次查询的数据，等待离散化
ll ans,tot,sumtot,num1,sum1;//tot记录当前总共有几种法术，sumtot代表所有法术的伤害和，num1代表易伤法术的数量，sum1为易伤法术的伤害和

int32_t main()
{
    IOS;
    getsp();
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>ask[i][0]>>ask[i][1];
        if(ask[i][1]>0) origin.push_back(ask[i][1]);
    }
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());//离散化
    for(ll i=0;i<n;i++)
    {
        if(ask[i][1]>0)
        {
            tot++;
            sumtot+=ask[i][1];
            if(ask[i][0]) num1++,sum1+=ask[i][1];
            ll tar=find(ask[i][1])+1;//tar为ask[i][1]在离散化数组对应的下标+1
            addtree(tar,1);//tree树状数组增加的是个数
            addtreesum(tar,ask[i][1]);//treesum树状数组记录的是前缀和，这里要加上权值
        }
        else
        {
            tot--;
            sumtot+=ask[i][1];
            if(ask[i][0]) num1--,sum1+=ask[i][1];
            ll tar=find(-ask[i][1])+1;
            addtree(tar,-1);
            addtreesum(tar,ask[i][1]);
        }
        if(num1)//存在易伤法术的情况
        {
            if(num1==1&&tot==1) cout<<sumtot<<endl;//易伤法术只有1种，且法术总共也只有1种，那么没有法术可被增伤。
            else
            {
                ll del=kth(tot-num1),delnow=kth(tot-num1-1);//tot-num1为没被易伤的法术数量，我们贪心选择最小的tot-num1个；
                //del为当前第tot-num1小的数的下标，delnow为当前第tot-num1-11小的数的下标，用于计算下面的特殊情况
                ll delsum=sumtreesum(del),delnowsum=sumtreesum(delnow);//计算最小的tot-num1以及to-num1-1个数的和为多少，
                if(tot-num1-1==0) delnowsum=0;//特判一下tot-num1-1为0的时候，此时的前缀和应该为0
                ll addsum=sumtot-delsum;//我们选择最大的num1个法术增伤，可以获得的增伤值
                //如果增伤值等于增伤法术的伤害总和，代表我们现在增伤的num1个法术全是增伤法术，这是不可能的，我们要选择伤害最大的非增伤法术取替换伤害最小的增伤法术
                if(addsum==sum1) addsum=sumtot-delnowsum-origin[kth(tot-num1+1)-1];//替换过程
                cout<<sumtot+addsum<<endl;
            }
        }
        else cout<<sumtot<<endl;
    }
}

