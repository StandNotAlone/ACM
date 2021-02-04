#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e5+7;

int n,m;
int num[maxn];
int l[maxn],r[maxn];
int cas[maxn*3];

vector<int>origin;

int find(int x)
{
    return (int)(lower_bound(origin.begin(),origin.end(),x)-origin.begin());
}

int paizi=0;

void work(int x)
{
    bool f=0;
    for(int i=m;i>0;i--)
    {
        if(num[i]>=x)
        {
            f=1;
            printf("%d",num[i]-paizi);
            paizi=num[i];
            break;
        }
    }
    if(!f) {printf("%d",num[1]-paizi);paizi=num[1];}
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        origin.push_back(l[i]);
        origin.push_back(r[i]+1);
    }
    sort(origin.begin(),origin.end());
    origin.erase(unique(origin.begin(),origin.end()),origin.end());
    for(int i=1;i<=m;i++)
    {
        cas[find(l[i])]++;
        cas[find(r[i]+1)]--;
    }
    ll pre=0,now=0;
    for(int i=0;i<origin.size();i++)
    {
        if(cas[i])
        {
            num[now]+=origin[i]-pre;
            pre=origin[i];
            now+=cas[i];
        }
    }

    for(int i=m-1;i>0;i--) num[i]+=num[i+1];
    num[0]=n;


    work((n+9)/10);
    printf(" ");
    work((n+3)/4);
    printf(" ");
    work((n+1)/2);
    printf("\n");
}
