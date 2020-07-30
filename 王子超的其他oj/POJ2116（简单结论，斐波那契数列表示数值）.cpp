#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll F[51]={1,2};
int a[51],b[51],c[51];
ll lena,lenb,lenc;
ll numa,numb,numc;

int main()
{
    //IOS;
    for(ll i=2;i<51;i++)
        F[i]=F[i-1]+F[i-2];
    string s1,s2;
    while(cin>>s1>>s2)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        numa=numb=numc=0;
        ll l1=s1.size(),l2=s2.size();
        for(ll i=0;i<l1;i++)
        {
            if(s1[i]=='1')
            {
                numa+=F[l1-i-1];
            }
        }
        for(ll i=0;i<l2;i++)
        {
            if(s2[i]=='1')
            {
                numb+=F[l2-i-1];
            }
        }
        numc=numa+numb;
        lena=lenb=lenc=-1;
        for(ll i=50;i>=0;i--)
        {
            if(numa>=F[i])
            {
                numa-=F[i];
                a[i]=1;
                if(lena==-1) lena=i;
            }
            if(numb>=F[i])
            {
                numb-=F[i];
                b[i]=1;
                if(lenb==-1) lenb=i;
            }
            if(numc>=F[i])
            {
                numc-=F[i];
                c[i]=1;
                if(lenc==-1) lenc=i;
            }
        }
        if(lena==-1) lena=0;
        if(lenb==-1) lenb=0;
        if(lenc==-1) lenc=0;
        for(ll i=0;i<lenc-lena+2;i++) printf(" ");
        for(ll i=lena;i>=0;i--) printf("%d",a[i]);
        printf("\n");
        printf("+");
        for(ll i=0;i<lenc-lenb+1;i++) printf(" ");
        for(ll i=lenb;i>=0;i--) printf("%d",b[i]);
        printf("\n");
        printf("  ");
        for(ll i=0;i<=lenc;i++) printf("-");
        printf("\n");
        printf("  ");
        for(ll i=lenc;i>=0;i--) printf("%d",c[i]);
        printf("\n\n");
    }
}
