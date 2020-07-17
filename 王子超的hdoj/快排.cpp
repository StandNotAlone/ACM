void qsort(int L,int R)
{
    int x=num[(L+R)/2],i=L,j=R;
    while(i<=j)
    {
        while(num[i]<x) i++;
        while(num[j]>x) j--;
        if(i<=j) swap(num[i++],num[j--]);
    }
    if(i<R) qsort(i,R);
    if(j>L) qsort(L,j);
}