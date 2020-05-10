#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<queue>
#define INF 0x7f7f7f7f //2139062143
#define INF1 0x3f3f3f3f //1061109567
#define INF2 2147483647
#define longlongINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
using namespace std;

const int N=3e5+10;
int a[N][4],t[N*2][2];                  //a数组存储每个方块的四个边，t[i]则表示边存在i的是哪两块
vector<int>vct;

int main()
{
    memset(t,0,sizeof(t));
    memset(a,0,sizeof(a));
    int n,flag=0,tmp[4];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])                //将边块关系存储到t数组中
            {
                int tmp=a[i][j];
                if(t[tmp][0]) t[tmp][1]=i;
                else t[tmp][0]=i;
            }
        }
        swap(a[i][0],a[i][2]);          //题目中的边是按照逆时针顺序给的，不方便我们从上到下从左到右模拟，交换0和2边即可变为顺时针
        for(int j=0;j<4;j++)
        {
            if(!a[i][j]&&!a[i][(j+1)%4]) flag=i;
        }
    }
    if(!flag) return 0*puts("impossible");//是否存在能作为角落的方块
    for(int j=0;j<4;j++)                   //将该方块旋转到我们想要的方向
    {
        if(!a[flag][j]&&!a[flag][(j+1)%4])
        {
            tmp[0]=tmp[1]=0;
            tmp[2]=a[flag][(j+2)%4];
            tmp[3]=a[flag][(j+3)%4];
            break;
        }
    }
    vct.push_back(flag);
    for(int j=0;j<4;j++) a[flag][j]=tmp[j];
    while(1)            //这里处理模拟的第一行，并随后计算出长度m
    {
        int now=vct.back();
        if(!a[now][2]) break;           //如果右侧边是0则代表第一行已经摆好
        int right=a[now][2];            //right存储当前块的右侧边
        int next;
        if(t[right][0]==now) next=t[right][1]; //如果0存储的就是现在这一块了，那么下一块就是1存储的那一块
        else next=t[right][0];
        for(int j=0;j<4;j++)    //旋转到我们想要的方向
        {
            if(a[next][j]==right)
            {
                tmp[0]=a[next][j];
                tmp[1]=a[next][(j+1)%4];
                tmp[2]=a[next][(j+2)%4];
                tmp[3]=a[next][(j+3)%4];
                break;
            }
        }
        for(int j=0;j<4;j++) a[next][j]=tmp[j];
        if(a[next][1]) return 0*puts("impossible"); //如果上侧边不是0则无法摆出
        vct.push_back(next);
    }
    int m=(int)vct.size();
    if(n%m) return 0*puts("impossible");   //如果无法摆成矩阵则不合题意
    if(n==m)            //特判只有一行的k情况
    {
        for(int i=0;i<m;i++) if(a[vct[i]][3]) return 0*puts("impossible");
    }
    for(int i=m;i<n;i++)
    {
        int now=vct[i-m];  //now存储的是上方的那个已经摆好的方块
        if(!a[now][3]) return 0*puts("impossible"); //如果上方方块的下侧边是0则不合题意
        int down=a[now][3];   //这里按照上侧边和上方方块下侧边相同来摆
        int next;
        if(t[down][0]==now) next=t[down][1];
        else next=t[down][0];
        for(int j=0;j<4;j++)
        {
            if(a[next][j]==down)
            {
                tmp[0]=a[next][(j+3)%4];
                tmp[1]=a[next][j];
                tmp[2]=a[next][(j+1)%4];
                tmp[3]=a[next][(j+2)%4];
                break;
            }
        }
        for(int j=0;j<4;j++) a[next][j]=tmp[j];
        if(i%m==0&&a[next][0]) return 0*puts("impossible");   //判定不符合题意的情况
        if(i%m==m-1&&a[next][2]) return 0*puts("impossible");
        if(i%m>0&&(a[next][0]!=a[vct[i-1]][2]||a[next][0]==0)) return 0*puts("impossible");
        if(i>=n-m&&a[next][3]) return 0*puts("impossible"); //注意当前是最后一行则下侧边不能是非0
        //不是最后一行的情况上面已经对now判断过了
        vct.push_back(next);
    }
    printf("%d %d",n/m,m);
    for(int i=0;i<n;i++)
    {
        if(i%m==0) printf("\n");
        printf("%d ",vct[i]);
    }
}
