#include<cstdio>
#include<math.h>
int check(int num)
{
    int t=1;
   for(int i=2; i<=sqrt(num); i++)
   {
       if(num%i==0)
       {
           t=0;
           break;
       }

   }

   if(t==1)return 1;
   else return 0;

}
int main()
{
    int s;
    while(scanf("%d",&s)!=EOF)
    {
        int i=3;
        int count = 0,f1,f2;
        while(1)
        {
            int t=0;

            t= check(i);
           if(t==1)
           {
               t= check(i+2);
               if(t==1)
               {
                   f1=i;
                   f2=i+2;
                   count++;
                   if(s==count)break;
               }
           }

           i+=2;
        }

        printf("(%d, %d)\n",f1,f2);

    }

    return 0;
}
