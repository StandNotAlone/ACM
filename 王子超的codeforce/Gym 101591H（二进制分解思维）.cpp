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

//����Ҫ�����Ǵ�1��ʼ���������ɸ�*2-1����*2+1�Ĳ�����ﵽĿ�����֣���ʵ���ǿ��Թ۲쵽���۽���ʲô���Ĳ�����󶼻���һ�����������ż��ֱ������޽�
//ע�⵽���ﶼ��*2��+-1�Ĳ�����������ǽ�Ŀ�����ֶ����Ʒֽ������
//����Ҫ��ʶ�����ǲ��۽���ʲô������ĩβ�����ֶ���1��ÿ�ν���*2����������ж�����������һ��ĩβ��0����+1-1������ĩβ������1
//�������ڶ�λ�����+1��ʣ�µ���1�������-1��ʣ�µ���0����ʶ����һ��֮�󣬴Ӷ����Ʒֽ��ĩβ��ʼ��ǰ�ƾͿ�����

int main()
{
    #ifdef local
    freopen("amplifiers.in","r",stdin);
    freopen("amplifiers.out","w",stdout);
    #endif
    ll n;
    vector<int>am;  //�洢����˳��
    cin>>n;
    if(n%2==0) cout<<"No solution"; //ż��ֱ������޽�
    else
    {
        while(n!=1)
        {
            if(n/2%2)   //�жϵ����ڶ�λ��0����1������ѹ�����1���ǲ���2
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
        if(am.size()) cout<<am[am.size()-1];//ע��ʵ�ʲ�����˳�������ѹ���˳�����෴��
        for(int i=am.size()-2;i>=0;i--)
            cout<<' '<<am[i];
        cout<<endl;
    }
}
