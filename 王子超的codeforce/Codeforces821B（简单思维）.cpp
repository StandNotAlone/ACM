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

//���ǻᷢ��������ʽ��Ϊx=(b-y)*m�����ѷ��ֶ���ÿ������y����Ӧ��x����һ������������-1/m��б�ʲ��ѷ���y��ȡֵ��Χ��С��ֻ��[0,b]
//���ֱ��forһ��y��ȡֵ��Χ������[0,y][0,x]�������Χ�����е�ĺ�������;Ϳ�����
//�����㹫ʽ��ʵ�������ƣ�x�Ĳ�����(1+x)*x*(1+y)/2��y�Ĳ�����(1+y)*y*(1+x)/2

int main()
{
    ios::sync_with_stdio(false);
    ll m,b;
    cin>>m>>b;
    ll ans=0,t;
    for(ll y=0;y<=b;y++)    //������ʵӦ����һ���©��y=0��ʱ�������Ҫ�����Ҳ�ĵ�ȡ���Ļ������������û�иߵģ���ô�⻹�㲻������أ����Ӧ���������һ�����Ͻ��ĵط�
    {
        ll x=(b-y)*m;
        t=(1+x)*(1+y)*(x+y)/2;
        if(t>ans) ans=t;
    }
    cout<<ans<<endl;
}
