#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
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
//ios::sync_with_stdio(false);
using namespace std;
#define local
#ifdef local
#endif

//其实如果忽略掉那个取整符号我们可以观察到它其实是个对勾函数x+1+d/(x+1)-1，因此我们找sqrt（d)就可以了
//但是sqrt可能是个小数，然后返回值只会是一个整数，我们实际要找的是距离sqrt（d）最接近的整数
//因此我们还要考虑sqrt+1后的情况是不是最优的

int t,n,d;
 
int judge(int x)    //计算当前x的结果，注意这里用的是d/x
{
    int ans=x-1+d/x;
    if(d%x) ans++;
    return ans;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        if(d==1) cout<<"YES"<<endl; //注意特判1
        else
        {
            int t;
            int x=sqrt(d);
            t=judge(x);
            if(judge(x+1)<t) t=judge(x+1);//考虑向上+1度情况是否更优
            if(t>n) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}
