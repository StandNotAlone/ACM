#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=1e2+7;
const double eps=1e-6;
const int mod=1e9+7;

char field[maxn][maxn];//存油田地图
int n,m;

void dfs(int x,int y){//通过dfs搜索，把与(x,y)相连的所有油田地块修改为无油
    field[x][y]='*';//修改当前位置为无油
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++){//检索周围8个格子
            int tempx=x+i;
            int tempy=y+j;
            if(tempx>=0&&tempx<n&&tempy>=0&&tempy<m&&field[tempx][tempy]=='@') dfs(tempx,tempy);
            //检索位置未出矩阵范围，且为油田地块，则对其递归使用dfs继续搜索
        }
}

int main(){
    while(scanf("%d%d",&n,&m),m){
        for(int i=0;i<n;i++) scanf("%s",field[i]);
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)//检索整个矩阵地图
                if(field[i][j]=='@') {//发现一块新油田，利用dfs搜索将这块油田全部修改为无油区，使得后续不会重复搜索到这块油田
                    ans++;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
}
