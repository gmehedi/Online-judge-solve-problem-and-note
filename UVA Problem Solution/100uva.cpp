
#include<cstdio>
int main()
{
     long int i,j;
     int c;

    while(scanf("%ld %ld",&i,&j)==2)
    {
        if( (i>0 && i<1000000 ) && (j>0 && j< 1000000 ) )
        {
            printf("%ld %ld ",i,j);
            if(i>j)
            {
                long int temp=i;
                            i=j;
                            j=temp;
            }
            c=0;

            while(i<=j)
            {
                int count=1;
               long  int n1=j;
                while(1)
                {
                    if(n1%2==0)n1=n1/2;
                    else
                    n1=3*n1+1;
                    count++;
                    if(n1==1)break;
               }

                if(c<count)c=count;
                j--;
                if(j==1)break;

          }
         printf("%d\n",c);

     }

 }

return 0;
}
