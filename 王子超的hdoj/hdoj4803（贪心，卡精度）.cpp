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
#ifdef local
#endif

#define maxn
using namespace std;

//��һ��Ӧ���˸�bfs����tle����ʶ�����Ǹ�̰�ĺ�д���˽ⷨ���Ǳ����ȿ����������Ǿ��ȵķ������Ǻ���ע�Ͳ���ѭ��д���ı��ⶼҪ����

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x>y) printf("-1\n");
        else
        {
            double ave=(y+0.999999)/x;      //��һ�⿨���ȿ�����̬��ը������һ����ѵ�ɣ�1e-6�ľ����ǿ��Է������ݷ���������
            int ans=x-1,ic;
            double nowy=1;
            for(int i=1;i<=x;i++)
            {
                ic=ave*i-nowy;
                ans+=ic;
                nowy+=ic;
                nowy+=nowy/i;
            }
            /*
            int nowx=1;
            while(nowx<x||y-nowy>1e-15||nowy-y<1e-15)   //����ѭ��д��������ô�ľ��ȶ���tle���ؼ��������ж�nowy��y������������ϣ����˺ܾ�����Ҳû��������ĸ���������ݿ���������жϷ�������������
            {
                ic=ave*nowx-nowy;
                ans+=ic;
                nowy+=ic;
                if(nowx!=x)
                {
                    nowy+=nowy/nowx;
                    nowx++;
                }
            }*/
            printf("%d\n",ans);
        }
    }
}

