#include<cstdio>
int main()
{
    int i,a,b;
     int c;

    while(scanf("%d %d",&a,&b)==2)
    {

            c=0;
            printf("%d %d ",a,b);
            if(a>b)
            {
                int temp=a;
                a=b;
                b=temp;
            }

            for(i=b; i>=a; i--)
            {
                int count=1;
                int n=i;
                while(1)
                {
                    if(n==1)break;
                    if(n%2==0)n=n/2;
                    else
                    n=3*n+1;
                    count++;

               }
              if(c<=count)c=count;
          }
         printf("%d\n",c);

     }

return 0;
}
