#include<stdio.h>
int main()
{
    int n,h1,m1,s1,h2,m2,s2;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&h1,&m1,&s1,&h2,&m2,&s2);
        s1+=s2;
        if(s1>=60)
        {
            s1-=60;
            m1++;
        }
        m1+=m2;
        if(m1>=60)
        {
            m1-=60;
            h1++;
        }
        h1+=h2;
        printf("%d %d %d\n",h1,m1,s1);
    }
}
