#include<cstdio>
int main()
{
    long long int num,temp,t,n;
    scanf("%lld",&n);
    while(n--)
    {
        int count=0;
        scanf("%lld",&num);
        while(1)
        {
             temp=num;

             t=0;
             while(num!=0)
             {
                 t=t*10+(num%10);
                 num=num/10;
             }
             if(t==temp)
             {
                 printf("%d %lld\n",count,temp);
                 break;
             }
             else
            {
                num=temp+t;
                count++;

             }
       }
   }
    return 0;
}
