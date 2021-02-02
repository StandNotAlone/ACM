#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;
const int maxn=1e5+7;

bool flag[maxn];

int main()
{
    int n,k;scanf("%d%d",&n,&k);
    int cas=n/2;
    int sum=cas-1;
    if(n>5) sum++;
    if(k>sum) printf("-1\n");
    else
    {
        bool f=0;
        if(k==cas)
        {
            int temp=0,now=2;
            while(temp<k&&now<=n)
            {
                if(now!=6)
                {
                    temp++;
                    if(f) printf(" ");
                    else f=1;
                    printf("%d",now);
                    flag[now]=1;
                }
                now+=2;
            }
            if(f) printf(" ");
            else f=1;
            printf("6");
            flag[6]=1;
            if(temp<k)
            {
                printf(" 3");
                flag[3]=1;
            }
            for(int i=1;i<=n;i++)
            {
                if(!flag[i]) printf(" %d",i);
            }
        }
        else
        {
            for(int i=1;i<=k+1;i++)
            {
                if(f) printf(" ");
                else f=1;
                printf("%d",i*2);
                flag[i*2]=1;
            }
            for(int i=1;i<=n;i++)
            {
                if(!flag[i])
                {
                    if(f) printf(" ");
                    else f=1;
                    printf("%d",i);
                }
            }
        }
        printf("\n");
    }
}
