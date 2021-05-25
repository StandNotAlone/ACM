#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e6+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
int ans=0;

vector<int>cas;
char s[20];
int num[107];
bool f=0;
int dp[2][1030][1030];

int count(int x){
    int ret=0;
    for(int i=0;i<m;i++){
        ret+=(x>>i&1);
    }
    return ret;
}

bool check(int i,int cas){
    if(i<1) return 1;
    return !(cas&num[i]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<(1<<m);i++){
        bool flag=1;
        int pre=-3;
        for(int j=0;j<m;j++){
            if(i>>j&1){
                if(pre+2>=j) flag=0;
                pre=j;
            }
        }
        if(flag) cas.push_back(i);
    }

    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=0;j<m;j++){
            num[i]<<=1;
            if(s[j]=='H') num[i]++;
        }
    }

    for(int i=1;i<=n;i++){
        for(int t1=0;t1<cas.size();t1++)
            for(int t2=0;t2<cas.size();t2++)
                for(int t3=0;t3<cas.size();t3++){
                    int x=cas[t1],y=cas[t2],z=cas[t3];
                    if(x&y||y&z||x&z) continue;
                    if(check(i-2,x)&&check(i-1,y)&&check(i,z)){
                        dp[!f][y][z]=max(dp[f][x][y]+count(z),dp[!f][y][z]);
                        ans=max(ans,dp[!f][y][z]);
                    }
                }
        for(int j=0;j<1030;j++)
            for(int k=0;k<1030;k++)
                dp[f][j][k]=0;
        f=!f;
    }

    printf("%d\n",ans);
}
