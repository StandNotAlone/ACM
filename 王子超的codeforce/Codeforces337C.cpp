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
int main()
{
    long long n,m,k,ans=1,t,xx=1e9+9,tmp=2;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(n/k*(k-1)+n%k>=m) printf("%lld\n",m);   //�������ǳ�����һ��Ҳ�����������k�⣬��ô����ÿ��k-1�ʹ�һ�⣬һ�����־���k�⣬n/k*(k-1�������Դ�Ե��������ټ���n%k����������һ��Ҳ�����������k������ܶԵ�������������ֵ����m��ôֱ�����m
    else
    {
        t=m-n/k*(k-1)-n%k;//t������һ��Ҳ�����������k������£���Ȼ��Ҫ��Ե�����
        int t1=t+1;       //������ʵ����ע�⵽����ԭ��һ��Ҳ����ɵ�����£��ٶ��Ե��ǵ���Խǰ������ֵԽС���Թ�ʽ�����ᷢ����k*(2^(t+1)-2)�ټ���ʣ�������
        while(t1)           //���ÿ��������㣬ֱ�ӱ�����ᳬʱ
        {
            if(t1%2) ans=ans*tmp%xx;
            tmp=tmp*tmp%xx;
            t1/=2;
        }
        ans-=2;
        if(ans<0) ans+=xx;      //ע������ans-2�����Ϊ��������ʱҪ���һ��xx�����������
        ans=ans*k%xx;
        ans=(ans+m-k*t)%xx;
        printf("%lld\n",ans);       //�������ʱ����Ӽ��˷��ǵȼ۵ģ����ǳ����ǲ��ȼ۵ģ�����Ҫ�ر�ע�������ʱ����ܻ��ɸ���Ҫ�ֶ���һ��������
    }
}
