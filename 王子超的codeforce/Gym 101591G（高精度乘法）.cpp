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
#define local
#ifdef local
#endif
using namespace std;

//����Ҫ���������ax+b��k�η���ϵ���ܺͣ���x=1�������ϵ�����ˣ���ʵ������a+b��k�η���
//��������ע�⵽a+b��������200��k��20��200��20�η�������1e46������Ͱ�longlong�����ˣ��������Ҫ�ø߾��ȳ˷�
//д�˸��߾��˵ı�׼ģ�壬python10�в����ͽ����...�Դ������Ƿ����...��Ҳ��ѧpython..

vector<int>v1,v2,v3;//�������飬v1�����洢��ǰ�η��Ľ����v2�洢a+b��ֵ��v3���ڴ洢��һ��v1*��a+b���Ľ��
int a,b,k;

int main()
{
    ios::sync_with_stdio(false);
    freopen("vasya.in","r",stdin);
    freopen("vasya.out","w",stdout);
    cin>>a>>b>>k;
    v1.resize(100);
    v2.resize(100);
    v3.resize(100);
    for(int i=1;i<60;i++)
    {
        v1[i]=0;
        v2[i]=0;
        v3[i]=0;
    }
    a+=b;
    int len=0;          //len��¼��a+b��λ�����������v2�ĳ���
    while(a)            //��a+b����10���Ʒֽ��һλһλѹ�������У�ע������ǰ��˳���������ʵ�����෴��
    {
        len++;
        v1[len]=a%10;
        a/=10;
    }
    v2=v1;              //��a+b��ֵ���Ƹ�v2��v2��������������в������޸�
    int newlen=len;     //newlen�洢v1�ж���λ�������ȸ���ʼֵlen
    for(int i=2;i<=k;i++)
    {
        for(int j=1;j<=newlen;j++)      //�߾��˵�һ����������λ��v1��v2��˺�ӵ�v3���Ӧ��λ��
        {
            for(int k=1;k<=len;k++)
            {
                v3[j+k-1]+=v1[j]*v2[k]; //������˵3λ��200����4λ��2000�ǣ�3+4-1��=6λ��400000
            }
        }
        newlen=newlen+len-1;            //�³���Ҳ������һ��������ԭ��������������Ӽ�һ����Ȼ���滹Ҫ���ǽ�λ
        int x=0;
        for(int j=1;j<=newlen;j++)      //�����λ��ʼ���μ����λ�Ƿ���ڽ�λ���
        {
            v3[j]+=x;
            x=v3[j]/10;
            v3[j]%=10;
        }
        while(x)                        //�Ե�ǰ���λ�ж��Ƿ���ڽ�λ
        {
            newlen++;
            v3[newlen]=x%10;
            x/=10;
        }
        v1=v3;                          //����������ֵ��v1
        for(int j=1;j<60;j++)           //��v3���������´μ���
            v3[j]=0;
    }
    for(int i=newlen;i>0;i--)
        cout<<v1[i];
    cout<<endl;
}
