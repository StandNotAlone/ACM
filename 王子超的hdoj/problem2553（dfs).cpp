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
int sum,n;
struct Field
{
    int flag[11][11];   //0��ʾ��λ�ÿ��Է���
};
//����ÿһ��ֻ����һ������
void dfs(int x,struct Field field)  //���ϵ���dfs��x�����ڰڵڼ��е�����������ֻ�迼���·����ܰڵ�λ�þͿ�
{
    for(int i=1;i<=n;i++)   //iΪ�б꣬����һ������λ�ñ���һ��
    {
        if(field.flag[x][i]==0)
        {
            if(x==n) sum++;         //����Ѿ������һ������ô��������+1
            else
            {
                struct Field newfield=field;//���ǵ�ʱ����һ���µ�flag����
                for(int j=x+1;j<=n;j++)
                {
                    newfield.flag[j][i]=1; //�����·���λ�ò����԰�
                    if(i-j+x>0) newfield.flag[j][i-j+x]=1;//б�����²����԰ڡ�j-xΪ�еľ���,i�ӻ��߼�ȥ����Ϊ�е�λ��
                    if(i+j-x<=n) newfield.flag[j][i+j-x]=1;//б�����²��ɰ�
                }
                dfs(x+1,newfield);//dfs��һ��
            }
        }
    }
}

int main()
{
    int ans[11];
    for(n=1;n<11;n++)               //������ظ����ݹ��࣬���Դ�����¼�¸���nʱ���𰸾Ϳ�
    {
        sum=0;
        struct Field source;
        memset(source.flag,0,sizeof(source.flag));
        dfs(1,source);
        ans[n]=sum;
    }
    while(scanf("%d",&n),n)
    {
        printf("%d\n",ans[n]);
    }
}