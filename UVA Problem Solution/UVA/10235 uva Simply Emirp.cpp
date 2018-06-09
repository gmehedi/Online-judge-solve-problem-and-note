#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int long prime(int long n)
{
     int flag=1;
     int long root = sqrt(n);
     for(int long i=2; i<= root; i++)
       {
           if(n%i==0)
           {
               flag=0;
               break;
           }
        }
        if(flag==1) return n;

}

int long rev(int long temp)
{
    int t=0,reve=0;
    while(temp > 0)
    {
        t = (t *10) +(temp%10);
        temp = temp/10;
    }
     reve = t;
    return reve;
}
int main()
{
   int long n,tmp=0;

 while(scanf("%ld",&n)==1){
      if( n == prime(n) ){
            tmp=rev(n);
            if(tmp==prime(tmp)){
                  if(tmp==n)
                  printf("%ld is prime.\n",n);
                  else
                  printf("%ld is emirp.\n",n);
            }
                  else
                  printf("%ld is prime.\n",n);
      }
      else
      {
            printf("%d is not prime.\n",n);
      }
}
return 0;
}
