
#include<bits/stdc++.h>
#define N 1000003
using namespace std;
long long Mod(long long a,long long b)
{
    if(b==0)return 1;
    long long x = Mod(a,b/2);
    x= x*x%N;
    if(b%2) x=x*a%N;
    return x;
}

long long fac[N+1];

long long  Fac()
{
    fac[0]=1;
    for(int i=1; i<=N; i++)fac[i]= (fac[i-1]*i) %N;
}

long long ModularInverse( long long a )
{
    return Mod(a,N-2);
}
int main()
{
    int n,k,t;
    Fac();
    scanf("%d",&t);
    int cas=1;
    while( t-- )
    {
         scanf("%d%d",&n,&k);
         if(k>n) { printf("Case %d: 0\n",cas++); continue; }
         if(k==0){ printf("Case %d: 1\n",cas++); continue; }
         printf("Case %d: %lld\n",cas++,(fac[n]*ModularInverse(fac[k]) * ModularInverse(fac[n-k]))%N );

    }
    return 0;
}
