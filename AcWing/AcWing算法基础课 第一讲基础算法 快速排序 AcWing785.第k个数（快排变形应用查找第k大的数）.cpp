#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int n,k,num[maxn];

void qsort(int L,int R)
{
    int mid=num[(L+R)/2],l=L,r=R;
    while(l<=r)
    {
        while(num[l]<mid) l++;
        while(num[r]>mid) r--;
        if(l<=r) swap(num[l++],num[r--]);
    }
    if(r>L&&r>=k) qsort(L,r);
    if(l<R&&l<=k) qsort(l,R);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    k--;
    qsort(0,n-1);
    printf("%d\n",num[k]);
}