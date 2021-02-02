#include<bits/stdc++.h>
#define ll long long
#define INF 0x7f7f7f7f //2139062143
#define llINF 9223372036854775807
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string A,N;

int main()
{
    IOS
    cin>>A>>N;
    int a=A[A.size()-1]-'0';
    int x=0;
    for(int i=0;i<A.size();i++)
    {
        x=x*10+A[i]-'0';
        if(x>1000) x=1000+x%1000;
    }
    int temp=0;
    for(int i=0;i<N.size();i++)
    {
        temp=temp*10+N[i]-'0';
        if(temp>1000) temp=1000+temp%1000;
    }

    if(temp==1) printf("%d\n",a);
    else if(a!=2&&a!=3&&a!=7&&a!=8&&a!=4) printf("%d\n",a);
    else if(a==4) printf("6\n");
    else
    {
        if(a==2||a==8)
        {
            if(temp==2)
            {
                if(x%4) printf("4\n");
                else printf("6\n");
            }
            else printf("6\n");
        }
        else if(a==3)
        {
            int p=x/10%10;
            if(p%2==0) printf("7\n");
            else printf("3\n");
        }
        else
        {
            int p=x/10%10;
            if(p%2==0) printf("3\n");
            else printf("7\n");
        }
    }
}
