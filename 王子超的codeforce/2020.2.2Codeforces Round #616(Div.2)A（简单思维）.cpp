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
const int maxn=INF;

//一开始的解法想得过于复杂了，div2A题果然不会这么麻烦
//题意为给你一个n为的数字，要求你对这个数字删除一定数目的位数后（可以不删除，但是不可以删成空的）
//新的数必须满足不能被2整除，而各个位上的数加起来可以被2整除
//如果能得到这样一个数，输出任意一种情况（如果有前导0，略去）

//当时被这一句略去前导0误导了思维
//首先新的数不能被2整除，那么它的末尾只要是一个奇数即可，而它各位加起来能被2整除，也就是说它各位上的数中奇数的个数必须是偶数
//实际上奇数的个数必须是偶数的话，也就是说原来的数中至少存在两个位上是奇数，我们只需要输出其中任意的两位奇数就可以了...
//因为是奇数所以一定不可能是0，也就不需要考虑前导0的情况...输出任意一种（划重点）

string s;
vector<char>num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    while(t--)
    {
        num.clear();
        cin>>n;
        cin.get();
        getline(cin,s);
        for(int i=0;i<s.length();i++)
            if(s[i]&1) num.pb(s[i]);//字符'0'的ascii码是48，也就是说字符0-9的ascii码的奇偶性和对应数字是相同的，因此直接和1进行与位运算就可判断奇偶性
        if(num.size()<2) cout<<-1<<endl;
        else cout<<num[0]<<num[1]<<endl;
    }
}



