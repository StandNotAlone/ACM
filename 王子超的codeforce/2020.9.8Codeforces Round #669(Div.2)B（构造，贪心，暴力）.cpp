#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool flag[1007];//flag[i]记录i这个数字是否已经被使用

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>num(n);
        for(auto &x:num) cin>>x;
        memset(flag,0,sizeof(flag));
        vector<int>ans;//ans为我们最后构造的数列
        int tar=0;
        for(int i=0;i<n;i++)//找到最大的那个数字，放在最后构造数列的第一个位置
        {
            if(num[i]>num[tar])
            {
                tar=i;
            }
        }
        ans.push_back(num[tar]);
        flag[tar]=1;

        int temp=num[tar];//temp记录当前构造的ans数组中最后一个位置的值
        for(int i=1;i<n;i++)
        {
            int Max=0,tar=-1;//tar记录剩下未被使用的数字中，与temp的gcd值最大tar为多少
            for(int j=0;j<n;j++)
            {
                if(!flag[j])
                {
                    if(gcd(temp,num[j])>Max)//此处的tar有多个，取任意一个均可，原因见题解
                    {
                        Max=gcd(temp,num[j]);
                        tar=j;
                    }
                }
            }
            ans.push_back(num[tar]);
            flag[tar]=1;
            temp=gcd(temp,num[tar]);
        }

        for(int i=0;i<ans.size();i++)
        {
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
}

