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
//cin.tie(0);
using namespace std;
#define local
#ifdef local
#endif
const int maxn=INF;

//题意为给你n个自然数，你可以对其中任意的数作任意次的-1操作，要求满足整个数列只能出现一个峰（把值做成图）
//比赛时写的解法少想了一步，实现过程更加复杂
//首先思考的方向是这样的，从最后减法操作后构成的数列入手
//只能构成一个峰的话，对于峰左侧的数来说必须满足值大小不小于和数列首的距离，对于峰右侧的数来说必须满足值大小不小于和数列尾的距离
//思考到这一步后便很直接得去实现了，从左侧开始一直向右到尾部模拟一遍，再从右侧一直向左到首部模拟一遍，两种情况有一种满足即可
//实际不需要这么麻烦
//直接记录从左侧到右侧模拟到出现不符合的位置，即从左模拟的峰的位置
//再从右侧到左模拟到出现不符合的位置，即从右模拟的峰的位置
//两侧模拟的部分如果有交叉即为可行，也就是判断左模拟峰的位置是否在右模拟峰的右侧或者重合

//ll t,n,num[300010];
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin>>t;
//    while(t--)
//    {
//        int flag1=1,flag2=1;
//        cin>>n;
//        int cas=0;
//        for(int i=0;i<n;i++)
//        {
//            cin>>num[i];
//            if(flag1)
//            if(cas==0)
//            {
//                if(num[i]<i)
//                {
//                    cas++;
//                    if(num[i]<n-1-i) flag1=0;
//                    if(i>0&&n-1-i>=i-1) flag1=0;
//                }
//            }
//            else if(cas==1)
//            {
//                if(num[i]<n-1-i) flag1=0;
//            }
//        }
//        cas=0;
//        for(int i=n-1;i>=0;i--)
//        {
//            if(flag2)
//            if(cas==0)
//            {
//                if(num[i]<n-1-i)
//                {
//                    cas++;
//                    if(num[i]<i) flag2=0;
//                    if(i<n-1&&i>=n-1-i-1) flag2=0;
//                }
//            }
//            else if(cas==1)
//            {
//                if(num[i]<i) flag2=0;
//            }
//        }
//        if(flag1||flag2) cout<<"Yes"<<endl;
//        else cout<<"No"<<endl;
//    }
//}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        int preend=-1,sufend=n;
        for(int i=0;i<n;i++)    //寻找从左侧开始一直递增，第一个不满足条件的数的位置，即pre峰的最右侧可在位置
        {
            if(a[i]<i) break;
            preend=i;
        }
        for(int i=n-1;i>=0;i--)//寻找从右侧向左一直递增，第一个不满足数的位置，即suf峰的最左侧可在位置
        {
            if(a[i]<n-1-i) break;
            sufend=i;
        }
        if(preend>=sufend) cout<<"Yes"<<endl;//重叠或者pre峰在suf峰右侧
        else cout<<"No"<<endl;
    }
}
