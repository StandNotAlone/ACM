#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
vector<pair<int,int>>line;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int main(){
    IOS
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        line.push_back({x,y});
    }
    sort(line.begin(),line.end(),cmp);
    int ans=0,r=-1e9-7,tar=0;
    for(int i=0;i<n;i++){
        while(i<n&&line[i].first<=r) i++;
        if(i<n) ans++;
        r=line[i].second;
    }
    cout<<ans<<endl;
}

