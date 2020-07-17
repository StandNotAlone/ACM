#include<stdio.h>
#include<string.h>
int main()
{
    int n,x;
    char a[40];
    scanf("%d",&n);
    getchar();
    while(n)
    {
        gets(a);
        x=(a[0]-'0')*10+a[1]-'0';
        printf("He/She is from ");
        switch(x)
        {
            case 33:printf("Zhejiang,");break;
            case 11:printf("Beijing,");break;
            case 71:printf("Taiwan,");break;
            case 81:printf("Hong Kong,");break;
            case 82:printf("Macao,");break;
            case 54:printf("Tibet,");break;
            case 21:printf("Liaoning,");break;
            case 31:printf("Shanghai,");break;
        }
        printf("and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",a[10],a[11],a[12],a[13],a[6],a[7],a[8],a[9]);
        n--;
    }
    return 0;
}
