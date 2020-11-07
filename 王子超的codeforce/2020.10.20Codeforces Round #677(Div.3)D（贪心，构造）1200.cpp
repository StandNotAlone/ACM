#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>num(n);
        for(auto &x:num) cin>>x;
        int tar=-1;
        for(int i=1;i<n;i++)
            if(num[i]!=num[i-1])//寻找是否有标记值不同的两个点
            {
                tar=i;
                break;
            }
        if(tar==-1) cout<<"NO"<<endl;//所有点标记值相同，无法构造任何边
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
            {
                if(i!=tar-1)
                {
                    if(num[i]!=num[tar-1]) cout<<tar<<' '<<i+1<<endl;//如果标记值与tar-1下标点的值不同，则连接到tar-1点上
                    else cout<<tar+1<<' '<<i+1<<endl;//如果与tar-1点的标记值相同，则连接到tar点上，tar点与tar-1点标记值不同固必定符合要求
                }
            }
        }
    }
}
