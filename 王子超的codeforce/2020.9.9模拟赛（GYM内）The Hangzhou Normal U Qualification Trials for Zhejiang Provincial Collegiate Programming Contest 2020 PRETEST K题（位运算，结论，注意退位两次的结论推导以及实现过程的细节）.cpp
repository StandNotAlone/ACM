#include<bits/stdc++.h>
#define ll long long
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll s,x;
ll nums[60];
ll numx[60];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s>>x;
        if(s<x) cout<<-1<<endl;
        else
        {
            memset(nums,0,sizeof(nums));
            memset(numx,0,sizeof(numx));
            s-=x;
            int Max=0;
            for(int i=0;i<60;i++)
            {
                if(s&(1ll<<i)) nums[i]=1;
                if(x&(1ll<<i)) {numx[i]=1;Max=i;}
            }
            if(nums[0]) cout<<-1<<endl;
            else
            {
                for(int i=59;i>Max;i--)
                {
                    nums[i-1]+=nums[i]*2;
                }
                ll temp=nums[Max]/2*2;
                numx[Max]+=temp;
                nums[Max]-=temp;
                for(int i=Max;i>0;i--)
                {
                    numx[i-1]+=nums[i]*2;
                }
                temp=0;
                for(int i=Max-1;i>=0;i--) temp=max(temp,numx[i]);
                ll ans=temp+numx[Max];
                if(numx[Max]>1&&Max&&temp==3)
                {
                    numx[Max]-=2;
                    numx[Max-1]+=4;
                    bool f=1;
                    for(int i=Max-1;i>0;i--)
                    {
                        if(numx[i]>6) f=0;
                        if(numx[i]>4)
                        {
                            numx[i]-=2;
                            numx[i-1]+=4;
                        }
                    }
                    if(numx[0]>4) f=0;
                    if(f) ans--;
                }
                cout<<ans<<endl;
            }
        }
    }
}