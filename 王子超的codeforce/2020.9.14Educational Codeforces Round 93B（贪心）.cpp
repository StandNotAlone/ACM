#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>num;
int n;
int cas[107];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        num.clear();
        num.resize(n);
        deque<int>Q;//用于存储不锁定位置上的数字，排序后进行后续构造操作
        for(int i=0;i<n;i++) cin>>num[i];
        for(int i=0;i<n;i++)
        {
            cin>>cas[i];
            if(!cas[i]) Q.push_back(num[i]);
        }
        sort(Q.begin(),Q.end());
        for(int i=0;i<n;i++)
        {
            if(!cas[i])//对不锁定位置，我们依次按照从大到小的顺序把所有数字放进去。
            {
                num[i]=Q[Q.size()-1];
                Q.pop_back();
            }
        }
        for(int i=0;i<n;i++) cout<<num[i]<<' ';
        cout<<endl;
    }
}
