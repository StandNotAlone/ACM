#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll num[107][107];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cin>>num[i][j];
        ll ans=0;
        for(int i=1;i<=n/2;i++)//除了奇数行的中间行外，所有位置都有对应三个另外的位置要保持相同
        {
            for(int j=1;j<=m/2;j++)
            {
                vector<ll>temp;
                temp.push_back(num[i][j]);
                temp.push_back(num[i][m-j+1]);//同一行的另一个数
                temp.push_back(num[n-i+1][j]);//同一列的另一个数
                temp.push_back(num[n-i+1][m-j+1]);//关于矩阵中心对称的另一个数
                sort(temp.begin(),temp.end());
                for(auto &x:temp) ans+=abs(x-temp[2]);
            }
            if(m&1) ans+=abs(num[i][m/2+1]-num[n-i+1][m/2+1]);//中间列是特殊情况
        }
        if(n&1)//奇数行的中间那一行额外处理，此时每个位置需要保持相同的数只有另外一个
        {
            for(int j=1;j<=m/2;j++) ans+=abs(num[n/2+1][j]-num[n/2+1][m-j+1]);
        }
        cout<<ans<<endl;
    }
}
