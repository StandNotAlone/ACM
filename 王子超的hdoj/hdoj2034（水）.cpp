#include<stdio.h>
#include<string.h>
int a[100];

void qsort(int l,int r)
{
    int q=l,p=r,mid=a[(l+r)/2],i,j,t;
    while(q<=p)
    {
        while(a[q]<mid)q++;
        while(a[p]>mid)p--;
        if(q<=p)
        {
            t=a[q];
            a[q]=a[p];
            a[p]=t;
            q++;
            p--;
        }
    }
    if(q<r) qsort(q,r);
    if(p>l) qsort(l,p);
}

int main()
{
    int n,m,flag[100],b,sum,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        sum=n;
        memset(flag,0,sizeof(flag));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            flag[i]=1;
        }
        qsort(0,n-1);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b);
            for(j=0;j<n;j++)
                if(flag[j]&&a[j]==b)
                {
                    flag[j]=0;
                    sum--;
                    if(sum==0) break;
                }
        }
        if(sum)
        {
            for(i=0;i<n;i++)
                if(flag[i]) printf("%d ",a[i]);
            printf("\n");
        }
        else printf("NULL\n");
    }
}
