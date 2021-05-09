#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=6e5+7;
const double eps=1e-6;
const int mod=1e9+7;

int n,m;
int s[maxn],root[maxn],tot;//root[i]保存s[]数组前i个的tire树根节点
int trie[maxn*24][2],latest[maxn*24];//latest既是end数组，也记录了子树中的值在s[]数组中的最大下标

void insert(int i,int deep,int pre,int now){
    //i是s[]数组的下标位置，deep代表目前是二进制从第到高第几位(从0开始)
    //pre为上一棵tire树，now为当前tire树
    if(deep<0){latest[now]=i;return;}
    int net=s[i]>>deep&1;//计算s[i]二进制第deep位的值
    if(pre) trie[now][net^1]=trie[pre][net^1];//如果前一棵树存在，复制另一状态
    trie[now][net]=++tot;//为当前新增数据添加新节点
    insert(i,deep-1,trie[pre][net],trie[now][net]);
    latest[now]=max(latest[trie[now][0]],latest[trie[now][1]]);
}

int ask(int deep,int x,int now,int lim){
    //查询now结点与x异或的最大值是多少，下标不能低于lim
    if(deep<0) return s[latest[now]]^x;
    int net=x>>deep&1;
    if(latest[trie[now][net^1]]>=lim) return ask(deep-1,x,trie[now][net^1],lim);
    //如果当前位相反的情况存在，则递归去找该子树中的最大值
    else return ask(deep-1,x,trie[now][net],lim);
}

int main(){
    scanf("%d%d",&n,&m);
    latest[0]=-1;
    root[0]=++tot;
    insert(0,23,0,root[0]);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        s[i]=s[i-1]^x;
        root[i]=++tot;
        insert(i,23,root[i-1],root[i]);
    }
    for(int i=1;i<=m;i++){
        char c;
        getchar();
        scanf("%c",&c);
        if(c=='A'){
            int x;scanf("%d",&x);
            s[n+1]=s[n]^x;
            n++;
            root[n]=++tot;
            insert(n,23,root[n-1],root[n]);
        }
        else{
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",ask(23,s[n]^x,root[r-1],l-1));
        }
    }
}
/*
5 5
2 6 4 3 6
A 1
Q 3 5 4
A 4
Q 5 7 0
Q 3 6 6
*/
