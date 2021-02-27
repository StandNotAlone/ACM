#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,s,t;
vector<pair<int,int>>line;

bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}

int main(){
    IOS
    cin>>s>>t;
    cin>>n;
    int ans=1,r=-1e9-7;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        if(x>s) line.push_back({x,y});
        else r=max(r,y);
    }
    sort(line.begin(),line.end(),cmp);
    for(int i=0;i<line.size();){
        if(r>=t) break;
        int temp=-1e9-7;
        while(i<line.size()&&line[i].first<=r){
            temp=max(temp,line[i].second);
            i++;
        }
        if(temp>r) {r=temp;ans++;}
        else break;
    }
    if(r>=t) cout<<ans<<endl;
    else cout<<-1<<endl;
}

