#include<stdio.h>
#include<string.h>

void qsort(int q,int p,int work[1001][2])
{
    int l=q,r=p,x=(q+p)/2,mid=work[x][1],t;
    while(l<=r)
    {
        while(work[l][1]>mid||work[l][1]==mid&&work[l][0]>work[x][0]) l++;
        while(work[r][1]<mid||work[r][1]==mid&&work[r][0]<work[x][0]) r--;
        if(l<=r)
        {
            t=work[l][0];
            work[l][0]=work[r][0];
            work[r][0]=t;
            t=work[l][1];
            work[l][1]=work[r][1];
            work[r][1]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p,work);
    if(r>q) qsort(q,r,work);
}

int main()
{
    int t,n,red,work[1001][2],day[1001],i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&work[i][0]);
        for(i=1;i<=n;i++)
            scanf("%d",&work[i][1]);
        memset(day,0,sizeof(day));
        qsort(1,n,work);
        red=0;
        for(i=1;i<=n;i++)
        {
            for(j=work[i][0];j>0;j--)
                if(day[j]==0)
                {
                    day[j]=1;
                    break;
                }
            if(j==0) red+=work[i][1];
        }
        printf("%d\n",red);
    }
}
