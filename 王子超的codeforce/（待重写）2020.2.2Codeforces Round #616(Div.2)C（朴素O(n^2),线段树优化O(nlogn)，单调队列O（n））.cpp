#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
//#include<bits/stdc++.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ifstream f1(".txt");
//ofstream f2(".txt");
//ios::sync_with_stdio(false);
using namespace std;
#define local
#ifdef local
#endif
const int maxn=3510;

//单调队列部分待重写



//题意为你和n-1个朋友发现了一个长度为n的数列
//你和你的朋友按照一定的先后顺序从这个数列里取数，只能从数列的首部或者尾部取数
//你是第m个取数的人，而你最多可以控制k个朋友的取数方案（你可以决定他们取首部还是尾部），当你已经决定控制哪些人，第一个人开始选择后，不能再改变控制的方案
//其他未被控制的人的取数方案是随机的，可能是首部也可能是尾部（他们不一定要取首部尾部中大的那一个）
//你会在首部尾部中选其中更大的那一个数x，但是由于会有一部分人的选择方案是随机的，也就是你选的时候首部和尾部的数不是确定的
//输出你可以保证获得的最小的x

//使用dl记录在我们选择之前有多少人是被我们控制的，sr记录我们选择之前有多少人是不被控制的
//在dl个人选择完之后，剩余的数列长度为n-dl,再由sr个人任意从首部尾部取，
//当我们选择的时候，数列长度为n-dl-sr,这个数列是dl个人取完后数列的一个连续子序列
//那么我们可能的选择的数就是这些连续子序列的首部和尾部，他们的下标在剩余数列内的下标为(1,sr+1)（n-dl-sr,n)
//其中下标1是首部的时候对应的尾部是n-dl-sr,实际上我们直接暴力搜索一遍所有长度为n-dl的数列，再对每个数列寻找所有可能情况，复杂度为O(n^2),1e7左右完全可行
//朴素写法在注释代码段第一部分

//然后还有用线段树优化后的O(nlogn)版本,在注释代码第二部分

//单调队列的O(n)版本在最后部分，理解很浅显，待重做

//ll t,n,m,k,num[4000];
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin>>t;
//    while(t--)
//    {
//        cin>>n>>m>>k;
//        for(ll i=0;i<n;i++)
//            cin>>num[i];
//        ll dl,sr;
//        dl=min(m-1,k);
//        sr=m-1-dl;
//        ll len=n-dl;
//        ll ans=-llINF;
//        for(ll i=len-1;i<n;i++)
//        {
//            ll x=llINF;
//            for(int j=i-len+1;j<=i-len+1+sr;j++)
//            {
//                ll X=max(num[j],num[j+len-1-sr]);
//                x=min(x,X);
//            }
//            ans=max(ans,x);
//        }
//        cout<<ans<<endl;
//    }
//}



//ll A[maxn],n,m,k,dl,sr,len;
//
//struct SegmentTree
//{
//    ll l,r;
//    ll ans;
//};
//
//vector<SegmentTree>ST;
//
//void buildST(ll l,ll r,ll loca)
//{
//    //cout<<l<<' '<<r<<' '<<loca<<endl;
//    ST[loca].l=l;
//    ST[loca].r=r;
//    if(l==r)
//    {
//        ST[loca].ans=max(A[l],A[l+len-1-sr]);//当取到根节点的时候与右侧len-1-sr距离的点比较大小，取大的值
//                                             //即模拟了对前面m-1个人取完后我们在剩余数列的首尾部分取大的数
//                                             //ask函数只考虑搜索左侧的部分，因此这里的数据只记录与右侧比较
//        return;
//    }
//    ll mid=l+((r-l)>>1);
//    buildST(l,mid,2*loca);
//    buildST(mid+1,r,2*loca+1);
//    ST[loca].ans=min(ST[loca*2].ans,ST[loca*2+1].ans);
//}
//
//ll askST(ll l,ll r,ll loca)
//{
//    if(l<=ST[loca].l&&r>=ST[loca].r) return ST[loca].ans;
//    ll mid=ST[loca].l+((ST[loca].r-ST[loca].l)>>1);
//    ll val=INF;
//    if(l<=mid) val=min(val,askST(l,r,loca*2));
//    if(r>mid) val=min(val,askST(l,r,loca*2+1));
//    return val;
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n>>m>>k;
//        for(ll i=1;i<=n;i++) cin>>A[i];
//        dl=min(m-1,k);
//        sr=m-1-dl;
//        len=n-dl;
//        ST.clear();
//        ST.resize(4*n);
//        buildST(1,n,1);
//        ll ans=-llINF;
//        ST[0];
//        for(ll i=len;i<=n;i++)
//        {
//            ans=max(ans,askST(i-len+1,i-len+1+sr,1));
//        }
//        cout<<ans<<endl;
//    }
//}
//

ll n,m,k,dl,sr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        dl=min(m-1,k);
        sr=m-dl;            //注意这里的sr和上两个版本的不同，多包含了一个自己本身
        vector<ll>num(n);
        for(auto &x:num)
            cin>>x;
        vector<ll>b(m);
        for(ll i=0;i<m;i++)
            b[i]=max(num[i],num[i+n-m]);
        //n-dl为待判定数列长度
        ll ans=-llINF;
        deque<ll>a;
        for(ll i=0,j=0;i<=dl;i++)//i为当前判断数列长度的左侧
        {
            while(a.size()&&a.front()<i) //下标在i左侧的全部出列
                a.pop_front();
            while(j<i+sr)
            {
                while(a.size()&&b[a.back()]>=b[j])
                    a.pop_back();
                a.pb(j++);
            }
            ans=max(ans,b[a.front()]);//a.front()存储了当前数列最小的情况
        }
        cout<<ans<<endl;
    }
}
