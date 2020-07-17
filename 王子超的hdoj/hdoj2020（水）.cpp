#include<stdio.h>
#include<math.h>
int a[200];
void qs(int l,int r)
{
    int mid,t,tl,tr;
    tl=l;
    tr=r;
    mid=fabs(a[(l+r)/2]);
    while(tl<=tr)
    {
        while(fabs(a[tl])>mid) tl++;
        while(fabs(a[tr])<mid) tr--;
        if(tl<=tr)
        {
            t=a[tr];
            a[tr]=a[tl];
            a[tl]=t;
            tl++;
            tr--;
        }
        if(tl<r) qs(tl,r);
        if(tr>l) qs(l,tr);
    }
}
int main()
{
    int n,i;
    while(scanf("%d",&n),n!=0)
    {
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        qs(1,n);
        for(i=1;i<n;i++) printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}
