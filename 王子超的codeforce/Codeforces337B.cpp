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
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
using namespace std;

long long gcd(long a,long b)
{
    if(b) return gcd(b,a%b);
    else return a;
}

int main()
{
    long long a,b,c,d,x,y,t;
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    //if(a<b) swap(a,b);
    //if(c<d) swap(c,d);                //�������Ļ�͵�Ӱ�ǲ�������ת��...
    if(a*d<b*c)                         //�����ȿ��Է��µĻ�ִ�е�һ���֣��Ų���ִ��else����
    {                                   //��������������ʵӦ����a*(d/c)<b��������ĿҪ������������������Ҫ��֤���ӷ�ĸ������
        y=b*c;                          //��Ӱ��ռ����ķ�ĸ��b*c�������һ��c)������Ҳ��Ӧ���һ��c���a*d
        x=y-a*d;
    }
    else
    {
        y=a*d;
        x=y-b*c;
    }
    t=gcd(y,x);
    x/=t;                               //��ȡ���ӷ�ĸ�����Լ��Ȼ���ȥ��������ӷ�ĸ����
    y/=t;
    printf("%lld/%lld\n",x,y);
}
