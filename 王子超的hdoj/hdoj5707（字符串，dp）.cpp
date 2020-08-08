#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<unordered_set>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=2e3+7;

bool flag[maxn][maxn];//flag[i][j]代表字符串c的长度匹配到i时，匹配字符串a的长度为j时是否可行，此时对应的匹配字符串b的长度为i-j

int32_t main()
{
    IOS;
    string a,b,c;
    while(cin>>a>>b>>c)
    {
        memset(flag,0,sizeof(flag));
        flag[0][0]=1;//长度均为0的时候是我们的初始情况，置为1
        int lena=(int)a.size();
        int lenb=(int)b.size();
        int lenc=(int)c.size();
        for(int i=1;i<=lenc;i++)//i为字符串c的匹配长度
        {
            for(int j=0;j<=i;j++)//j为字符串a的匹配长度
            {
                int k=i-j;//k为字符串c的匹配长度
                //以下为从字符串c的匹配长度为i-1时状态转移至当前的长度为i时
                if(j<=lena&&a[j-1]==c[i-1]&&flag[i-1][j-1]) flag[i][j]=1;//字符串c的第i个字符（下标对应i-1）与字符串a匹配的情况
                if(k<=lenb&&b[k-1]==c[i-1]&&flag[i-1][j]) flag[i][j]=1;//字符串c的第i个字符（下标对应i-1）与字符串b匹配的情况
            }
        }
        bool f=0;
        for(int i=0;i<=lenc;i++)
            if(flag[lenc][i]) f=1;
        if(f&&lenc==lena+lenb) cout<<"Yes"<<endl;//记得特判下c的长度要等于a+b，不然a+b大于c的情况下也是可以匹配成功的
        else cout<<"No"<<endl;
    }
}
