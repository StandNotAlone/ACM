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

#define maxn
using namespace std;
vector<int>v1,v2,v3;
int a,b,k;

//������Ǹ��Ķ����..�����˾ͳ����򵥵�һ���⣬ע��һ��ÿ��ѧԺ�ĵڶ��к������ִ�������Ǽ��ſο�������һ��Եĳɼ���

int main()
{
    ios::sync_with_stdio(false);        //ȡ��cin��stdioͬ����߶�д�ٶ�,�ڴ��������������cin����ᳬʱ����һ�������
    #ifdef local
    freopen("tests.in","r",stdin);
    freopen("tests.out","w",stdout);
    #endif
    int n,m,ans=0;
    cin>>n>>m;
    int grade[110];
    for(int i=1;i<=m;i++)
        cin>>grade[i];
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        char str1[110];
        cin.get();
        cin.getline(str1,110);
        int t,cas[110];
        cin>>t;
        for(int j=1;j<=t;j++)
            cin>>cas[j];
        int x1,y1,z1;
        for(int j=1;j<=t;j++)
        {
            cin>>x1>>y1>>z1;
            sum+=2;
            if(grade[cas[j]]>=x1)sum++;
            if(grade[cas[j]]>=y1)sum++;
            if(grade[cas[j]]>=z1)sum++;
        }
        int numsb;
        cin>>numsb;
        for(int j=1;j<=numsb;j++)
        {
            char sb[110];
            cin.get();
            cin.getline(sb,110);
            int target;
            cin>>target;
            if(sum>=target)
            {
                cout<<str1<<' '<<sb<<endl;
                ans++;
            }
        }
    }
    if(ans==0) cout<<"Army";
}
