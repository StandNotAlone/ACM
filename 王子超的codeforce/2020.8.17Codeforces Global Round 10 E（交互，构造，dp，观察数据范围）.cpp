#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll n;
ll sum;
ll field[30][30];//存储我们构建的矩阵每个位置的值，我们构造的矩阵的所有路线，对于field[i][j]来说，向下走的任意方案，一定比向右走的所有方案得到的值都更大
//以此来得到dir数组，做到O(1)指示我们的路径方向
ll dir[30][30];//dir[i][j]代表从当前位置向右走再到终点，可以获得的最大值，用来指示我们走到(i,j)时应该向下还是向右走
//实际上这个路线是先往后走一步，再向下走到底，再向右走到底
ll Data[30][30];//Data[i][j]代表从(i,j)走到（i,n)得到的值，就是一个反向的前缀和，辅助计算
ll dp[30][30];//dp[i][j]存储从(1,1)走到（i,j)有几种方案

void getdp()
{
    dp[1][0]=1;
    for(ll i=1;i<=25;i++)
    {
        for(ll j=1;j<=25;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}

void getfield()
{
    for(ll i=1;i<=n;i++) field[1][i]=field[i][n]=0;//构造第一行和最后一列为0
    ll x=1;//x为对于(i,j)位置来说，从(1,1)先向右走到(1,j)，再向下走到(i,j)，再向右的最小值，即继续向右走到底再向下走到底
    for(ll j=n-1;j;j--)
    {
        ll temp=0;//temp记录当前field[i][j]的上方所有值的和
        for(ll i=2;i<=n;i++)
        {
            //见x代表的值
            //第一行和最后一列我们构造的全为0，因此只需要让x减去field[i][j]上方和右方的累加值即为field[i][j]应当构造的值
            field[i][j]=x-temp-Data[i][j+1];
            temp+=field[i][j];//累加竖直上方的前缀和
            Data[i][j]=field[i][j]+Data[i][j+1];//累加右方的前缀和
            x+=dp[n-i+1][n-j];//对于field[i][j]来说，它第一步向右走，再走到终点的情况即为[n-i+1,n-j]的矩阵的方案数
            //那么对于field[i+1][j]来说，它向右走的最小值就应该比field[i][j]的最小值加上对应的dp值方案数
        }
    }
}

void getdir()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<n;j++)
        {
            for(ll k=i;k<=n;k++)
                dir[i][j]+=field[k][j+1];
            for(ll k=j+2;k<=n;k++)
                dir[i][j]+=field[n][k];
            dir[i][j]+=field[i][j];
        }
    }
}


int32_t main()
{
    IOS;
    cin>>n;
    getdp();
    getfield();
    getdir();
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
            cout<<field[i][j]<<' ';
        cout<<endl;
    }
    ll k;
    cin>>k;
    while(k--)
    {
        cin>>sum;
        ll nowr=1,nowc=1;//nowr为我们当前所在行，nowc为我们当前所在列
        while(nowr<=n&&nowc<=n)
        {
            cout<<nowr<<' '<<nowc<<endl;
            if(dir[nowr][nowc]<sum||nowc==n) {sum-=field[nowr][nowc];nowr++;}
            //如果我们当前的值，比向右走得到的最大值都大的话，代表当前方案应该在下方
            else {sum-=field[nowr][nowc];nowc++;}
            //如果我们当前的值，比向右走得到的最大值要小或等于，代表当前方案应该在右侧
        }
        cout<<endl;
    }
}
