#include<stdio.h>
#include<math.h>
int main()
{
  int m, n, i;
  double x, temp;
  while(scanf("%d %d",&m,&n)!=EOF)
    {
      x = 0;
      temp = m;
      for(i=1;i<=n;i++)
      {
        x += temp;
        temp = sqrt (temp);
      }
      printf("%.2lf\n",x);
  }
  return 0;
}
