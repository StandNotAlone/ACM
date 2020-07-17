#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
using namespace std;

int main()
{
    int n,i,x[110],y[110],s;
    while(scanf("%d",&n),n)
    {
        s=0;
        scanf("%d%d%d%d",&x[1],&y[1],&x[2],&y[2]);
        for(i=3;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            s+=(x[i-1]-x[1])*(y[i]-y[1])-(y[i-1]-y[1])*(x[i]-x[1]);   //将n多边形分割成n-2个三角形然后利用向量叉乘的二维特殊情况公式求取三角形面积，证明过程见百度百科向量积
        }                                                             //向量叉乘公式可以通过几何方式推得.个人推法
        printf("%.1lf\n",s/2.0);
    }
}
