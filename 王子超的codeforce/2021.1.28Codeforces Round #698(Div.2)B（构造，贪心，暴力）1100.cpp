#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;cin>>n>>d;
        while(n--)
        {
            int x;cin>>x;
            if(x>=d*10) cout<<"YES"<<endl;
            else
            {
                bool flag=0;
                for(int i=0;i<10;i++)//暴力枚举十位用了什么数字
                {
                    int temp=i*10;
                    if(x>temp&&(x-temp)%d==0) flag=1;//如果能整除则存在
                }
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
}
