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

//����i�β���(i��n-i+1)ÿ�β����ѵ�i������n-i+1�����ѵ���
//��ᷢ�ֵ�һ�β����ǰѵ�1������n�����򣬵ڶ��β����ѵ�2������n-1������
//�����β����ѵ�3������n-2������........
//���ѷ��֣�ÿ��������ÿ�β������ǺͶԳ�λ�õ����ѽ���λ��
//��ÿ�����ѽ����Ĵ���������λ���йأ�������߽���루�����ұ߽磬�����������ߵ���໹���Ҳࣩ
//��������±��1��n����ô�±�1�����Ѿ��ǽ�����1�ν������±�2�����Ѿ��ǽ�����2�ν���...
//���������ν�����ǰ��λ�û���������ż���ν�����λ�ò���
//���ֱ��forһ��1��n/2��������ʱ��ǰ�󽻻�λ�÷��ã�ż����ʱ��ǰ��ԭλ�÷���

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int num[200010];    //��ų�ʼ���ѵļ�ֵ��λ��
    for(int i=1;i<=n;i++)
        cin>>num[i];
    int flag[200010];   //��Ų����������������λ��
    for(int i=1;i<=n/2;i++)
    {
        if(i%2)
        {
            flag[i]=n+1-i;  //�������ǰ��λ�ý�������
            flag[n+1-i]=i;
        }
        else
        {
            flag[i]=i;      //ż�����ǰ��λ�ò���ֱ�ӷ���
            flag[n+1-i]=n+1-i;
        }
    }
    if(n%2) flag[n/2+1]=n/2+1;//n��������ʱ�����м�λ�÷�������ԭλ�ã��������flag����û�н��и���ֵ��
    cout<<num[flag[1]];
    for(int i=2;i<=n;i++)   //����flag�����ŵ�λ���±��������ֵ����
        cout<<' '<<num[flag[i]];
    cout<<endl;
}
