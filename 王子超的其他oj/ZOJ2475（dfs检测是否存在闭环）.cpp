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
using namespace std;

int N,E,flag,field[110];    //field���ڴ洢�õ��Ƿ��Ѿ����ߵ���
vector<int>road[110];       //��̬����road[i]�洢i���·������Щ

void dfs(int x)
{
    if(!flag) return;
    int len=road[x].size();
    for(int i=0;i<len;i++)
    {
        if(field[road[x][i]])   //����߻���ԭ���߹���·��˵������ʧ��
        {
            flag=0;
            return;
        }
        else
        {
            field[road[x][i]]=1;    //���׼��dfs���̾Ͳ�˵��
            dfs(road[x][i]);
            field[road[x][i]]=0;
        }
    }
}

int main()
{
    while(scanf("%d",&N),N>0)
    {
        for(int i=0;i<110;i++)
            road[i].clear();
        memset(field,0,sizeof(field));
        int a,b;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&a,&b);
            if(a!=b) road[a].pb(b);         //ע���Լ������Լ��ǺϷ��ģ����Բ���¼��ȥ
        }
        scanf("%d",&E);
        field[E]=1;
        flag=1;
        dfs(E);
        if(flag) printf("Yes\n");       //һ��ʼ����˴�д��YESNOwa����...���������ģ�����ʧ��
        else printf("No\n");
    }
}


