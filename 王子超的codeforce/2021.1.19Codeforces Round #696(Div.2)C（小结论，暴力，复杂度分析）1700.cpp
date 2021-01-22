#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int cas[1000000+7];//cas[i]标记i这个值出现了几次

int main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>num(2*n);
        for(int i=0;i<2*n;i++) cin>>num[i];
        sort(num.begin(),num.end());
        bool F=0;//标记是否存在可行解
        int st=0,sum;
        vector<pair<int,int>>out;//保存每步取出了哪两个数，输出用
        for(int o=0;o+1<2*n;o++)//枚举第一步操作时，与最大值向加的数的位置
        {
            for(int i=0;i<2*n;i++) cas[num[i]]++;
            int tar=2*n-1;
            st=sum=num[tar]+num[o];//st记录第一步的和，用于输出，sum记录当前需要找的和为多少
            F=1;
            for(int i=0;i<n;i++)
            {
                while(cas[num[tar]]==0) tar--;
                cas[num[tar]]--;//当前最大的数减去一个
                cas[sum-num[tar]]--;//与当前最大的数加起来等于sum的数减去一个
                if(cas[sum-num[tar]]<0||cas[num[tar]]<0)
                {
                    cas[sum-num[tar]]=cas[num[tar]]=0;//这里的清零和上面if判断的cas[num[tar]]
                    //都是容易疏忽的点
                    F=0;
                    break;
                }
                out.push_back({sum-num[tar],num[tar]});
                sum=num[tar];
            }
            if(F) break;
            for(int i=0;i<2*n;i++) cas[num[i]]=0;//清零操作
            out.clear();
        }
        if(F)
        {
            cout<<"YES"<<endl;
            cout<<st<<endl;
            for(int i=0;i<n;i++) cout<<out[i].first<<' '<<out[i].second<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
