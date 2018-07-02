#include<bits/stdc++.h>
#define N 1000000
//const int INF = 0x3f3f3f3f;
using namespace std;

bool Check(int n, int pos) {return (bool)(n&(1<<pos));}
int sett(int n,int pos) { return (n|(1<<pos) );}

int64_t sign[N/32];
int64_t prime[1000000];

void Sieve()
{
    //memset(sign,true,sizeof sign);
    for(int i=3; i*i<N; i+=2)
    {
        if(Check(sign[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=N; j+=(i<<1)) sign[j>>5]=sett(sign[j>>5],j&31);
        }
    }
//cout <<sign[3]<<endl;
    prime[0]=2;
    int k=1;
   for(int i=3; i<=N; i+=2)if(Check(sign[i>>5],i&31) ==0) prime[k++]=i;
   prime[k++]=INT_MAX;

}

int Mod(char *pointer,int prme)
{
    int mod=0;
    for(int i=0; pointer[i]; i++)
    {
        mod=(mod*10+pointer[i]-'0')%prme;
    }
    return mod;
}
int main()
{
    Sieve();
    int l;
    char ch[10000];
    while(scanf("%s%d",ch,&l)==2 && l!=0)
    {
         int i;
         for( i=0; prime[i]<l; i++)
         {
             if(!Mod(ch,prime[i]))break;
         }
         if(prime[i]>=l) printf("GOOD\n");
         else printf("BAD %d\n",prime[i]);
    }



    return 0;
}

