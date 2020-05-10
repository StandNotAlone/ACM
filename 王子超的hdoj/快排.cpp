void qsort(int q,int p)
{
    int l=q,r=p,mid=w[(q+p)/2],t;
    while(l<=r)
    {
        while(w[l]<mid)l++;
        while(w[r]>mid)r--;
        if(l<=r)
        {
            t=w[l];
            w[l]=w[r];
            w[r]=t;
            l++;
            r--;
        }
    }
    if(l<p) qsort(l,p);
    if(r>q) qsort(q,r);
}
