#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define pi 3.141592653589793238462643383279502
using namespace std;
int main()
{
    long long x1,x2;
    while(scanf("%llx%llx",&x1,&x2)!=EOF)   //������llxֱ�Ӱ���16����������,ϵͳ���Զ�ʶ���Сд
    {
        if(x1+x2<0)                         //��ʱ������ʱ���漰��16�������ڴ�洢��ʽ��ԭ��𰸻��������Ҫ�Ĳ�һ��
        {
            printf("-");                    //��ʱֱ�����һ������,�ٰ�������ȫ��ȡ�෴��ʹ�𰸱�������Ϳ�����
            x1*=-1;
            x2*=-1;
        }
        printf("%llX\n",x1+x2);             //�������Ҫ��llX��ʾ�ô�д��ĸ���
    }
}
