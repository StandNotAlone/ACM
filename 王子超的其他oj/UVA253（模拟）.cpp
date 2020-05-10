#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
using namespace std;
                                    //可以发现按照题目给的骰子六面编码方法，对称两面的编号加起来刚好是7
                                    //color数组存储读入的字符串，那么骰子1的对称两面编号相加是5
int cases[6][4]=                    //用cases[i]数组存储当第i面在底部时，侧面的依次编号顺序。用于之后的旋转比对
{
    1,2,4,3,
    0,3,5,2,
    0,1,5,4,
    0,4,5,1,
    0,2,5,3,
    1,3,4,2
};

int figure2[4]={7,8,10,9};          //让骰子2的第一面在底部，即color[6]。figure存储侧面的依次角标顺序方便代码

int main()
{
    char color[20];
    while(scanf("%s",color)!=EOF)
    {
        int Flag=0;                 //Flag标志两骰子是否旋转后等价，这里的实现思想是骰子2的1面朝下，然后骰子1的6面依次朝下，旋转去比对
        for(int i=0;i<6;i++)
        {
            if(color[i]==color[6]&&color[5-i]==color[11]) //如果骰子的底面和顶面颜色相同则开始旋转比对
            {
                for(int j=0;j<4;j++)                    //旋转j次90度
                {
                    int flag=1;                         //flag标志这种旋转情况两骰子是否等价
                    for(int k=0;k<4;k++)                //对比四面
                    if(color[cases[i][(j+k)%4]]!=color[figure2[k]]) flag=0; //(j+k)%4为旋转j次后侧面的第k面
                    if(flag)
                    {
                        Flag=1;
                        break;
                    }
                }
            }
        }
        if(Flag) printf("TRUE\n");
        else printf("FALSE\n");
    }
}
