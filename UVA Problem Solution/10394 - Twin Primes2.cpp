
#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 20000000
using namespace std;

unsigned long long int tp[N];
char p[N];
int main()
{
      int i,j,root,t=1;
     long long int n=0;
    memset(p,1,sizeof p);


            p[0]=p[1]=0;
            root=sqrt(N);
            for(i=2;i<=root;i++)
                        if(p[i]==1){
                              for(j=i+i;j<=N;j=j+i)
                                          p[j]=0;
                         }

                         for(i=3;i<N;i++){
                                    if(p[i]==1 && p[i+2]==1){
                                          tp[t++]=i;
                                    }

                         }
                         while(scanf("%lld",&n)==1){
                         printf("(%llu, %llu)\n",tp[n],tp[n]+2);


                         }



      return 0;
}
