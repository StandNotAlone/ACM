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

int affe[100010],sum[100010],sum1[100010],sum2[100010];//affe[i]�洢�ô�ׯ�Ƿ񱻸�Ⱦ��sum[i]������ׯi�����ׯ1�ľ��룬sum1[i]������ׯi�ͽڵ�1�ľ��룬sum2[i]������ׯi�ͽڵ�2�ľ���
//�ڵ�1�ͽڵ�2�ǰ������и�Ⱦ��ׯ����С������ֱ���ϵ������˵�
vector<int>road[100010];//��̬����road[i]�洢��i����ׯ��ͬ�Ĵ�ׯ������þ�̬��100010*100010�ᱬ�ڴ�

void dfs(int now,int before,int sum[100010]) //dfs���������ʼ��ľ���
{
    int len=road[now].size();
    for(int i=0;i<len;i++)
    {
        if(road[now][i]!=before)
        {
            sum[road[now][i]]=sum[now]+1;
            dfs(road[now][i],now,sum);
        }
    }
}

int main()
{
    int n,m,d,x,y;
    memset(affe,0,sizeof(affe));
    memset(sum,0,sizeof(sum));
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        affe[x]=1;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        road[x].pb(y);
        road[y].pb(x);
    }
    dfs(1,0,sum);
    int max1=-1,n1;
    for(int i=1;i<=n;i++)           //��һ��dfs�ҵ���Ⱦ��ׯ�кʹ�ׯ1��Զ��һ���㣬Ϊ��Ⱦ��ׯ���ɵ�������ֱ����һ���˵�
    {
        if(affe[i]&&sum[i]>max1)
        {
            max1=sum[i];
            n1=i;
        }
    }
    dfs(n1,0,sum1);
    int max2=-1,n2;
    for(int i=1;i<=n;i++)           //�ڶ���dfs�Ӷ˵�1��ʼ���ҵ������о���ö˵���Զ�ĵ㣬����ֱ������һ���˵�
    {
        if(affe[i]&&sum1[i]>max2)
        {
            max2=sum1[i];
            n2=i;
        }
    }
    dfs(n2,0,sum2);
    int ans=0;
    for(int i=1;i<=n;i++)           //���������˵�����<=d�ĵ���������Ⱦ��ׯ�ľ���Ҳ<=d
        if(sum1[i]<=d&&sum2[i]<=d) ans++;
    printf("%d\n",ans);
}


