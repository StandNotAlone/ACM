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
#define pi 3.14159265358979323846264338327950254
using namespace std;

//这道题目用到了许多的知识，首先讲一下它的解题思路，题目给定的6种字符仔细观察可以发现，他们内部包含的空白块个数恰好都是不同的，而且题意说了一堆其实就是表达一个意思，这些字符用点阵来给你，1代表黑色0代表白色，任意拉伸不改变字符的基本架构，因此可以用dfs搜索检测字符当中出现了几个白块
//在检测有多少个字符，每个字符中间又有多少个空白块之前，我们需要先把字符外的部分处理为-1代表不能被搜索。由于最左上角的那个点有可能是黑色，而且如果边缘是黑点的话，直接对n*4m的矩阵进行搜索边缘无法处理完所有外部点。因此原本需要用n*4m的矩阵来保存点阵（m是16进制数所以要用到四个位置），我们应该用（n+1）*（4m+2）的矩阵来保存，即在头尾各自加上一行一列，这样子就可以对[0][0]dfs，可以达到处理完所有字符外部点功能
//在处理完字符外部点后，对输入的矩阵部分进行搜索，当出现1的时候代表检测到了字符，此时开始dfs搜索，并建立一个值cas=0来存储空白块出现的个数，当空白块即出现0时令cas+1，并且再执行一个dfs将所有该空白块中的0变为-1，最后通过cas的值来对应ans数组（存储有多少个空白块的那个字符出现了多少次）中的值+1


int ox[16][4]=
{
    {0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
    {0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
    {1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
    {1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1},
};//这里存储了16进制数的对应二进制，方便对输入数据的转化
int field[205][205],n,m,cas;//field数组存储点阵，cas存储当前搜索到的字符里有几个空白块
int direc[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//方向数组，上下左右移动

void dfs1(int x,int y)
{
    if(x<0||x>n+1||y<0||y>4*m+2) return;
    if(field[x][y]) return;
    field[x][y]=-1;
    for(int i=0;i<4;i++)
        dfs1(x+direc[i][0],y+direc[i][1]);
}       //标准的dfs，将与当前0连通的所有0赋值为-1

void dfs2(int x,int y)
{
    if(field[x][y]==-1) return;
    else if(field[x][y]==0)
         {
             cas++;
             dfs1(x,y);
         }
    else
    {
        field[x][y]=-1;
        for(int i=0;i<4;i++)
           dfs2(x+direc[i][0],y+direc[i][1]);
    }
}//在标准的dfs里面增加了一个新的dfs和计数cas.这里由于main函数的for循环已经限定了范围并且已经处理过外围部分因此不需要考虑越界的情况

void map_print()
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=4*m+1;j++)
            printf("%4d",field[i][j]);
        printf("\n");
    }
}//测试用输出矩阵函数

int main()
{
    char s[52];
    int Case=0;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int ans[6];
        getchar();//这道题有点迷，这句话加不加都是对的。但是看不到数据也没办法知道数据到底是怎么样的
        memset(ans,0,sizeof(ans));
        memset(field,0,sizeof(field));
        for(int i=1;i<=n;i++)
        {
            cin.getline(s,205);
            for(int j=0;j<m;j++)
            {
                int x;
                if(s[j]>='0'&&s[j]<='9') x=s[j]-'0';
                else x=s[j]-'a'+10;
                for(int k=0;k<4;k++)
                    field[i][j*4+k+1]=ox[x][k];
            }
        }//将16进制转化为二进制存储到点阵中
        //map_print();
        dfs1(0,0);//对边缘部分预处理
        //map_print();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=4*m;j++)
                if(field[i][j]==1)
                {
                    cas=0;
                    dfs2(i,j);
                    ans[cas]++;
                }//检测字符并检测该字符中的空白块个数
        printf("Case %d: ",++Case);
        for(int i=0;i<ans[1];i++) printf("A");
        for(int i=0;i<ans[5];i++) printf("D");
        for(int i=0;i<ans[3];i++) printf("J");
        for(int i=0;i<ans[2];i++) printf("K");
        for(int i=0;i<ans[4];i++) printf("S");
        for(int i=0;i<ans[0];i++) printf("W");
        printf("\n");
    }
}
