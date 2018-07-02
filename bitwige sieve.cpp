#include<bits/stdc++.h>
#define N 100000000
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
   for(int i=3; i<=N; i+=2)if(Check(sign[i>>6],i&31) ==0) cout <<i<<endl;
}
int main()
{
    Sieve();
    int n,k=2;
    prime[1]=2;

    for(int i=3; i<=N; i+=2)
    if(Check(sign[i>>6],i&63) ==0)
    {
         prime[k++]=i; // cout <<k-1<<endl;
    }
   while(cin >>n)
    cout <<prime[n]<<endl;


    return 0;
}
