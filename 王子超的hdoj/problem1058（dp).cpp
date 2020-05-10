#include<stdio.h>
int main()
{
    int n,a[5843],sum,x2,x3,x5,x7,i=1;
    a[1]=1;
    x2=x3=x5=x7=1;
    while(i<5843)
    {
        while(a[x2]*2<=a[i]) x2++;
        while(a[x3]*3<=a[i]) x3++;
        while(a[x5]*5<=a[i]) x5++;
        while(a[x7]*7<=a[i]) x7++;
        sum=a[x2]*2;
        if(a[x3]*3<sum) sum=a[x3]*3;
        if(a[x5]*5<sum) sum=a[x5]*5;
        if(a[x7]*7<sum) sum=a[x7]*7;
        i++;
        a[i]=sum;
    }
    while(scanf("%d",&n),n)
    {
        printf("The %d",n);
        if(n%100>10&&n%100<20) printf("th");
        else if(n%10==1) printf("st");
             else if(n%10==2) printf("nd");
                  else if(n%10==3) printf("rd");
                  else printf("th");
        printf(" humble number is %d.\n",a[n]);
    }
}
