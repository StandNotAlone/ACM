#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1007;

int n;
int cas[maxn];//cas[i]的值为0或者1
//cas[i]=0代表第i列的操作次数和第0行的操作次数的奇偶性相同
//cas[i]=1代表第i列的操作次数和第0行的操作次数的奇偶性相反
string field1[maxn],field2[maxn];

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cas[i]=0;
        for(int i=0;i<n;i++) cin>>field1[i];
        for(int i=0;i<n;i++) cin>>field2[i];
        bool flag=1;
        //所有的奇偶性标记均与第一行的操作次数对比
        for(int j=0;j<n;j++)
        {
            if(abs(field1[0][j]-field2[0][j])) cas[j]=1;//如果原矩阵和目标矩阵这一位置的值不同
            //代表第0行的操作次数与第j列的操作次数加起来要是奇数，也就是两者的操作次数奇偶性相反
            else cas[j]=0;
        }
        for(int i=1;i<n;i++)
        {
            int temp;
            if(abs(field1[i][0]-field2[i][0])) temp=!cas[0];//根据第一列的情况判断第i行操作的奇偶性标记
            else temp=cas[0];
            for(int j=1;j<n;j++)
            {
                if(abs(field1[i][j]-field2[i][j]))
                {
                    if(temp==cas[j]) flag=0;//如果出现矛盾的情况则判断不可行
                }
                else
                {
                    if(temp!=cas[j]) flag=0;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
