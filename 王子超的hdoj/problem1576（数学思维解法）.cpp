#include<stdio.h>
int main()
{
    int T,n,i;
    long long b;//����longlong�͵Ļ����ݻᱬ��
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&n,&b);
        for(i=1;i<9973;i++)
            if(i*b%9973==n) break;
        printf("%d\n",i);
    }
    return 0;
}
