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

//���ûʲô�ѵģ�ֱ����������ģ��Ϳ����ˡ�
//����Ϊ��������ֵ����1�ĸ��ӣ��Ƿ�����Ӹø�λ�õ��������ҵ�һ�����ں������ҵ�һ�������ֵ��ӵ��ڸø���
//�ҵĴ��뻹����һ��֦..����������ôС��ʵ��������Ҫ

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int field[100][100];
    memset(field,0,sizeof(field));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>field[i][j];
    int flag=1;//flag�洢���������Ƿ���������
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(field[i][j]!=1)//������1��ʱ������ж�
            {
                int f=0;        //fΪ1����õ���������
                for(int k=1;k<=n;k++)
                {
                    for(int l=1;l<=n;l++)
                    {
                        if(field[k][j]+field[i][l]==field[i][j])
                        {
                            f=1;//�ҵ�����ĵ�����1������ѭ��
                            break;
                        }
                    }
                    if(f) break;//ͬ��
                }
                if(!f) flag=0;//�����������ʹflag��0
            }
        }
        if(!flag) break;    //������������ʱ����ѭ��
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
