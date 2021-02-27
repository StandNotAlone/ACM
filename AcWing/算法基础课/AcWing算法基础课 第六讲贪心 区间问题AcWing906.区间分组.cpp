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
    return a.first<b.first;
}

int main(){
    IOS
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        line.push_back({x,y});
    }
    sort(line.begin(),line.end(),cmp);
    priority_queue<int,vector<int>,greater<int>>heap;
    for(int i=0;i<n;i++){
        if(heap.size()&&heap.top()<line[i].first) heap.pop();
        heap.push(line[i].second);
    }
    cout<<heap.size()<<endl;
}

