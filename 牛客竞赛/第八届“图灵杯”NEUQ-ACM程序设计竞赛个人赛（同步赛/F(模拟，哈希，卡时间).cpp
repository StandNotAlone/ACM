#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn=30+7;
const int mod=998244353;

int read()      //整数读入挂
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

vector<string>grade[107];
int n;

struct Node
{
    int grade,num,sex;
};

unordered_map<string,Node>MAP;
char temp[10007];

int main()
{
    n=read();
    for(int i=0;i<n;i++)
    {
        string name;
        Node a;
        scanf("%s",temp);
        a.grade=read();
        a.sex=read();
        a.num=read();
        int len=strlen(temp);
        for(int i=0;i<len;i++)
         name+=temp[i];
        MAP[name]=a;
        grade[a.grade].push_back(name);
    }
    for(int i=0;i<=100;i++) sort(grade[i].begin(),grade[i].end());
    int k;cin>>k;
    while(k--)
    {
        int ope;cin>>ope;
        if(ope==1)
        {
            string name;
            scanf("%s",temp);
            int len=strlen(temp);
            for(int i=0;i<len;i++)
             name+=temp[i];
            Node a=MAP[name];
            printf("%d %d %d\n",a.grade,a.num,a.sex);
        }
        else
        {
            int x;cin>>x;
            for(int i=0;i<grade[x].size();i++)
            {
                for(int j=0;j<grade[x][i].size();j++)
                    printf("%c",grade[x][i][j]);
                printf("\n");
            }
        }
    }
}
