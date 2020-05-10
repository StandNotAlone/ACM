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
#define llINF 9223372036854775807
#define pi 3.141592653589793//23846264338327950254
#define pb push_back
#define ll long long
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//ios::sync_with_stdio(false);
#define local
#ifdef local
#endif
using namespace std;

//此题要求我们求出ax+b的k次方的系数总和，把x=1代入就是系数和了，其实就是求a+b的k次方。
//但是我们注意到a+b最大可能是200，k是20，200的20次方至少是1e46以上早就把longlong爆掉了，因此这里要用高精度乘法
//写了个高精乘的标准模板，python10行不到就解决了...自带大数是方便的...我也想学python..

vector<int>v1,v2,v3;//三个数组，v1用来存储当前次方的结果，v2存储a+b的值，v3用于存储下一次v1*（a+b）的结果
int a,b,k;

int main()
{
    ios::sync_with_stdio(false);
    freopen("vasya.in","r",stdin);
    freopen("vasya.out","w",stdout);
    cin>>a>>b>>k;
    v1.resize(100);
    v2.resize(100);
    v3.resize(100);
    for(int i=1;i<60;i++)
    {
        v1[i]=0;
        v2[i]=0;
        v3[i]=0;
    }
    a+=b;
    int len=0;          //len记录了a+b的位数，代表的是v2的长度
    while(a)            //将a+b按照10进制分解后一位一位压入数组中，注意这里前后顺序和我们现实里是相反的
    {
        len++;
        v1[len]=a%10;
        a/=10;
    }
    v2=v1;              //把a+b的值复制给v2，v2在整个计算过程中不进行修改
    int newlen=len;     //newlen存储v1有多少位，这里先赋初始值len
    for(int i=2;i<=k;i++)
    {
        for(int j=1;j<=newlen;j++)      //高精乘第一步，按各个位将v1和v2相乘后加到v3相对应的位上
        {
            for(int k=1;k<=len;k++)
            {
                v3[j+k-1]+=v1[j]*v2[k]; //举例来说3位的200乘以4位的2000是（3+4-1）=6位的400000
            }
        }
        newlen=newlen+len-1;            //新长度也和上面一样至少是原来两个数长度相加减一，当然后面还要考虑进位
        int x=0;
        for(int j=1;j<=newlen;j++)      //从最低位开始依次计算各位是否存在进位情况
        {
            v3[j]+=x;
            x=v3[j]/10;
            v3[j]%=10;
        }
        while(x)                        //对当前最高位判断是否存在进位
        {
            newlen++;
            v3[newlen]=x%10;
            x/=10;
        }
        v1=v3;                          //将计算结果赋值给v1
        for(int j=1;j<60;j++)           //对v3清零用于下次计算
            v3[j]=0;
    }
    for(int i=newlen;i>0;i--)
        cout<<v1[i];
    cout<<endl;
}
