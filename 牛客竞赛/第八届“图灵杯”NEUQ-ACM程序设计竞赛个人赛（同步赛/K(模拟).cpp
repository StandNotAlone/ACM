#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<char>c[4];
vector<int>num[4];
int cntc=0,cntn=0;

char change(char c)
{
    if(c=='Z') return 'b';
    if(c=='z') return 'B';
    return c+1;
}

int main()
{
    string s;cin>>s;
    for(int i=0;i<32;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            num[cntn].push_back(s[i]-'0');
            cntn=(cntn+1)%4;
        }
        else
        {
            c[cntc].push_back(s[i]);
            cntc=(cntc+1)%4;
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<num[i][j];k++)
                c[i][j]=change(c[i][j]);
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
            printf("%c",c[j][i]);
    }
    printf("\n");
}
