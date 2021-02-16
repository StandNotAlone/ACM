#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,num[maxn];

void qsort(int L,int R)
{
    int mid=num[(L+R)/2],l=L,r=R;
    while(l<=r)
    {
        while(num[l]<mid) l++;
        while(num[r]>mid) r--;
        if(l<=r) swap(num[l++],num[r--]);
    }
    if(r>L) qsort(L,r);
    if(l<R) qsort(l,R);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    qsort(0,n-1);
    for(int i=0;i<n;i++) printf("%d ",num[i]);
}


作者：standnotalone
链接：https://www.acwing.com/activity/content/code/content/390717/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。