#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int>num;
int n;
int cas[107];

bool cmp(int a,int b)
{
    return a>b;
}

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
        deque<int>Q;
        for(int i=0;i<n;i++) cin>>num[i];
        for(int i=0;i<n;i++)
        {
            cin>>cas[i];
            if(!cas[i]) Q.push_back(num[i]);
        }
        sort(Q.begin(),Q.end(),cmp);
        for(int i=0;i<n;i++)
        {
            if(!cas[i])
            {
                num[i]=Q[0];
                Q.pop_front();
            }
        }
        for(int i=0;i<n;i++) cout<<num[i]<<' ';
        cout<<endl;
    }
}