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

//T组数据，每组数据的第一行给一个数字n代表第二行给定字符串（只由0和1构成）的长度，第二个数字x为我们要寻找的情况
//我们要求用第二行给定的字符串，无限循环构成的无限长度字符串的任意前缀（可以为空），计算其中0的个数减去1的个数，需要等于x。要求输出满足该条件的前缀s字符串数
//思考过程大致如下
//方便说明将0的个数减去1的个数规定为数字t
//首先以不重复，只考虑第二行字符串一次循环的情况，比如样例1的字符串010010
//空前缀对应t=0
//第一位对应t=1
//第二位对应t=0
//....
//第五位对应t=1（这里只计算到第五位就可以了，不计算第六位的原因见下）
//再计算出整个字符串的t=2（还是算了第六位..)
//我们可以观察到，长度为6的前缀可以由空前缀+一个原字符串构成，那么它对应的t=空前缀的t（0）+整个字符串的t（2）=2
//同理长度为7的前缀可以由长度为1的前缀+一个原字符串构成，长度13的前缀可以由长度为1的前缀+两个原字符串构成，对应x计算方法如上
//因此我们只要从长度为0的前缀一直计算到长度为n-1的前缀对应的t1，整个字符串的对应的t2
//判断是否存在自然数y满足t1+y*t2=x即可，也就是可以转化为判断(x-t1)%t2是否等于0
//题目要求输出对应t=x的前缀的个数，如果存在无数个就输出-1
//从上方的推导过程可以观察到，整个原字符串对应的t2如果等于0，那么假设长度1的前缀，长度1+n,1+2n,1+3n....都会符合，这便是无数个的情况
//当t2!=0时，每个长度对应满足的情况最多只有1个，用(x-t1)%t2判断即可

int main()
{
    ios::sync_with_stdio(false);
    ll t,n,x;
    char s[100010];
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        cin.get();                          //血的教训.关闭cin的同步后不只是scanf，getchar也不可以混用了
        cin.getline(s,100010);
        ll cas=0;
        for(ll i=0;i<n;i++)
            if(s[i]=='0') cas++;
            else if(s[i]=='1') cas--;   //cas存储整个原字符串对应的0的个数减去1的个数的值
        if(cas==0)                      //特判cas=0的情况
        {
            ll flag=0;                  //flag存储最后输出的结果，如果没有找到满足的前缀则输出0，如果找到输出-1（无穷个）
            ll now=0;                   //now存储当前前缀的0的个数减去1的个数
            for(ll i=0;i<n;i++)
            {
                if(x==now)              //由于cas=0，因此(x-cas)%now==0直接转化为了x==now
                {
                    flag=-1;
                    break;
                }
                if(s[i]=='0') now++;
                else if(s[i]=='1') now--;
            }
            cout<<flag<<endl;
        }
        else
        {
            ll ans=0;
            ll now=0;
            for(ll i=0;i<n;i++)
            {
                if((x-now)*cas>=0&&(x-now)%cas==0) ans++;//前半部分的判断为x-now和cas要同号（即满足推导过程中的y要e为自然数）
                if(s[i]=='0') now++;
                else if(s[i]=='1') now--;
            }
            cout<<ans<<endl;
        }
    }
}
