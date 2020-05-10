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

int dis[200010],n,k;            //dis����洢�����ľ��룬0����δ���ߵ���

int bfs()
{
    queue<int>q;
    q.push(n);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        if(x>k)                 //�����ǰ��ֵ�Ѿ���kҪ������ô�ò�������+1����*2����ֻ����-1
        {
            int x1=x-1;
            if(dis[x1]==0)
            {
                dis[x1]=dis[x]+1;
                if(x1==k) return dis[k];
                q.push(x1);
            }
        }
        else
        {
            int x1=x-1,x2=x+1,x3=x*2;   //�ֱ��Ӧ-1��+1��*2����
            if(x1>=0&&dis[x1]==0)       //ע���ж��ǲ����ߵ�����ȥ��,����x>k��ʱ�������������������ûд
            {
                dis[x1]=dis[x]+1;
                if(x1==k) return dis[k];
                q.push(x1);
            }
            if(dis[x2]==0)
            {
                dis[x2]=dis[x]+1;
                if(x2==k) return dis[k];
                q.push(x2);
            }
            if(dis[x3]==0)
            {
                dis[x3]=dis[x]+1;
                if(x3==k) return dis[k];
                q.push(x3);
            }
        }
    }
    return -1;
}

int main()
{
    memset(dis,0,sizeof(dis));
    scanf("%d%d",&n,&k);
    if(n>=k) printf("%d\n",n-k); //���n����kС�Ļ���nֻ�ܲ��ϼ������ƶ��ӽ�k������С����
    else printf("%d\n",bfs());
}


