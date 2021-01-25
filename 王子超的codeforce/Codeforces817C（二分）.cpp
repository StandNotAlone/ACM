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
#define ll long long

#define local
#ifdef local
#endif

#define maxn
using namespace std;

ll n,s,ans=0;

//��������õ����ۣ�������ͷǴ����ķ�Χ����ȫ�ֿ��ģ�Ҳ���Ǵ���С���������ʼ������������������������˶��ֲ�����С�������������Ϳ�����

int judge(ll x)             //���x�ǲ���really big number
{
    ll sum=0,x1=x;
    while(x1)
    {
        sum+=x1%10;
        x1/=10;
    }
    if(x-sum>=s) return 1;
    else return 0;
}

ll bs()
{
    ll l=s,r=n;
    ll mid;
    while(l<r-1)        //������С���Ǹ��������ȥ����λ���ֵĺͺ���ܴ���Ҳ���ܵ���s��������l=rֱ������ѭ����������l=r-1ʱ������ȥ
    {
        mid=l+(r-l)/2;
        if(judge(mid)) r=mid;
        else l=mid;
    }
    if(judge(l)) return l;  //����࿪ʼ����ǲ��������
    if(judge(r)) return r;
    return -1;              //�����ǵĻ�����һ������
}

int main()
{
    scanf("%lld%lld",&n,&s);
    if(n>s)
    {
        ll num=bs();
        if(num>0)
        {
            ans=n-num+1;
        }
    }
    printf("%lld\n",ans);
}


