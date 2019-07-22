#include<bits/stdc++.h>
#define N 20000000
using namespace std;
long long prime[N];
bool sign[N];
void Seive()
{
    for(long long i=3; i*i<=N; i+=2)
    {
        if(sign[i])
        {
            for(long long j=i*i; j<=N; j+=i*2)
            {
                sign[j]=false;
            }
        }
    }
    int k=1;
    prime[0]=2;
    for(long long i=3; i<=N; i+=2)
    {
        if(sign[i])
        {
            prime[k++]=i;
        }
    }
}
int main()
{
    long long n,cnt[100000];
    memset(sign,true,sizeof sign);
    Seive();
    while(cin >>n && n)
    {
        int k=0;
         long long t=0;
        if(n<0)
        {
            t=n*-1;
        }
        else t=n;
        printf("%lld = ",n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(n==-1)
        {
            printf("-1\n");
            continue;
        }
        if(n<-1)
        {
            printf("-1 x ");
        }
        bool b=true;
        for(int i=0; prime[i]*prime[i]<=t; i++)
        {
            b=false;
            while(t%prime[i]==0)
            {
                printf("%d",prime[i]);
                t/=prime[i];
                if(t>=2)printf(" x ");

            }
        }
        if(t>=2)printf("%lld\n",t);
        else printf("\n");

    }

    return 0;
}
