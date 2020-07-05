#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
//#include<bits/stdc++.h>
#define INF 0x3f3f3f3f //1061109567
#define llINF 9223372036854775807
#define pi 3.141592653589793
#define ll long long
using namespace std;
const ll maxn=1e2+7;
const double eps=1e-10;
const ll mod=1e9+7;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

char s[maxn];



int dp[maxn][maxn];

int main()
{
//    IOS;//使用之后不要混用cin和scanf printf
    while(1)
    {
        scanf("%s",s+1);
        if(s[1]=='e') break;
        int len=strlen(s+1);
        for(int i=1;i<=len;i++)
            for(int j=1;j<=len;j++)
                dp[i][j]=0;
        for(int L=2;L<=len;L++)
        {
            for(int left=1;left+L-1<=len;left++)
            {
                int right=left+L-1;
                if(s[left]=='('&&s[right]==')'||s[left]=='['&&s[right]==']')
                    dp[left][right]=(L==2?2:dp[left+1][right-1]+2);
                for(int mid=left;mid<right;mid++)
                    dp[left][right]=max(dp[left][right],dp[left][mid]+dp[mid+1][right]);
            }
        }
        printf("%d\n",dp[1][len]);
    }
}


