#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define sup 2147483647
using namespace std;
int main()
{
    int i,j,n,h,dp[100001];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            dp[i]=sup;
        for(i=0;i<n;i++)
        {
            scanf("%d",&h);
            *lower_bound(dp,dp+n,h)=h;// �ú�����ȡ��dpͷָ�뵽dp+nָ��λ�ü���ڵ���h�ĵ�һ��ָ��
        }
        printf("%d\n",lower_bound(dp,dp+n,sup)-dp);
    }
}
