#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int main(){
    IOS
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        int lena=a.size(),lenb=b.size();
        int ans=0;
        for(int i=0;i<lena;i++)//枚举字符串a从哪个下标开始与字符串b比对
            for(int j=0;j<lenb;j++){//枚举字符串b从哪个下标开始与字符串a比对
                int k;//记录匹配长度
                for(k=0;i+k<lena&&j+k<lenb;k++)
                    if(a[i+k]!=b[j+k]) break;//不匹配或者超出长度限制后break
                ans=max(ans,k);//取最大的匹配长度
            }
        cout<<lena+lenb-ans*2<<endl;//总长度减去最大匹配长度的两倍，即为最少要删除的字符数量
    }
}

