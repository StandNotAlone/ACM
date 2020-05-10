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

//题意为给你一个只包括LRUD四个方向的路线，要求你从中删除尽可能短的连续子串后终点的位置和原来一样，输出删除子串的左右下标
//终点位置一样，其实也就是意味着在我们删除的连续子串中，L和R的个数要相等并且U和D的个数也要相等
//子串长度最大为2e5，如果我们暴力枚举所有偶数长度的子串，复杂度为O（n^2）TLE

//在这里用map来将复杂度降低到O(nlogn)   logn为map自身消耗

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        s.resize(n);
        for(char &c:s)
            cin>>c;
        pair<int,int>lr_ud={0,0};   //first记录R减去L的个数，second记录U减去D的个数，初始均为0
        map<pair<int,int>,int>M;    //map建立lr_ud和区间右侧位置下标的关系，表示当前为止LRUD个数情况等于lr_ud的区间最右侧的下标是哪个
        M[lr_ud]=0;                 //初始右侧下标为0
        int l=-1,r=INF;             //我们最后输出的左右下标，由于字符串中下标-1，所以实际输出的时候需要+1处理
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') lr_ud.first--;
            if(s[i]=='R') lr_ud.first++;
            if(s[i]=='U') lr_ud.second++;
            if(s[i]=='D') lr_ud.second--;
            if(M.count(lr_ud))      //代表如果当前lr_ud个数情况在前面部分的某个区间出现过
                                    //lr_ud相等的两个区间，不重叠的部分必然lr_ud值为0，也就是我们需要找的区间
            {
                if(r+1-l>i+1-M[lr_ud]) //对比前面部分已找到区间的长度和当前找到区间的长度，如果当前更小则更改记录值
                {
                    l=M[lr_ud];
                    r=i;
                }
            }
            M[lr_ud]=i+1; //更新当前lr_ud对应的最右侧下标
        }
        if(l==-1) cout<<-1<<endl;
        else cout<<l+1<<' '<<r+1<<endl;
    }
}



