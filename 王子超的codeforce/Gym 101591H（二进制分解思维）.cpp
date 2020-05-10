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

#define local



#define maxn
using namespace std;

//此题要求我们从1开始，进行若干个*2-1或者*2+1的操作后达到目标数字，其实我们可以观察到不论进行什么样的操作最后都会是一个奇数，因此偶数直接输出无解
//注意到这里都是*2和+-1的操作，因此我们将目标数字二进制分解后来看
//首先要认识到我们不论进行什么操作，末尾的数字都是1，每次进行*2操作会把所有二进制数左移一格并末尾补0，而+1-1操作后末尾都会是1
//而倒数第二位如果是+1则剩下的是1，如果是-1则剩下的是0，认识到这一点之后，从二进制分解后到末尾开始往前推就可以了

int main()
{
    #ifdef local
    freopen("amplifiers.in","r",stdin);
    freopen("amplifiers.out","w",stdout);
    #endif
    ll n;
    vector<int>am;  //存储操作顺序
    cin>>n;
    if(n%2==0) cout<<"No solution"; //偶数直接输出无解
    else
    {
        while(n!=1)
        {
            if(n/2%2)   //判断倒数第二位是0还是1，决定压入操作1还是操作2
            {
                am.pb(2);
                n/=2;
            }
            else
            {
                am.pb(1);
                n=n/2+1;
            }
        }
        cout<<am.size()<<endl;
        if(am.size()) cout<<am[am.size()-1];//注意实际操作的顺序和我们压入的顺序是相反的
        for(int i=am.size()-2;i>=0;i--)
            cout<<' '<<am[i];
        cout<<endl;
    }
}
