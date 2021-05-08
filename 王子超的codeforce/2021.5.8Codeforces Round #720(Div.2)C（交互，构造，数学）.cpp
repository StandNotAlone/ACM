#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e4+7;
const double eps=1e-6;
const int mod=1e9+7;

int n;
int num[maxn];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int tar1=-1,temp;
        for(int i=1;i<=n;i+=2){
            int now=(i==n?n-1:i);
            printf("? 2 %d %d %d\n",now,now+1,1);
            fflush(stdout);
            scanf("%d",&temp);
            if(temp==1) {tar1=now;break;}
            if(temp==2){
                printf("? 2 %d %d %d\n",now+1,now,1);
                fflush(stdout);
                scanf("%d",&temp);
                if(temp==1) {tar1=now+1;break;}
            }
        }
        for(int i=1;i<=n;i++){
            if(i==tar1) num[i]=1;
            else{
                printf("? 1 %d %d %d\n",tar1,i,n-1);
                fflush(stdout);
                scanf("%d",&num[i]);
            }
        }

        printf("!");
        fflush(stdout);
        for(int i=1;i<=n;i++){
            printf(" %d",num[i]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
    fflush(stdout);
}
