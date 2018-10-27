
#include<bits/stdc++.h>
#define maxl 122
#define ll long long
#define maxi 1000010
using namespace std;
bitset<maxi>b;
int prime[maxi];
int k=0;
void Prime()
{
    b[0]=true;
    for(int i=2; i*i<=maxi; i++) if(!b[i]) for(int j=i*i; j<=maxi; j=j+i )b[j]=true;
    k=0;
    for(int i=2; i<=maxi; i++)if(!b[i] ) prime[k++]=i;
}

ll Factorization(ll &num)
{
    ll temp=num,res=1;

    for(int i=0; prime[i]*prime[i]<=num && i<k; i++)
    {
        if(prime[i] > temp) break;
        int ans=0;
        while(temp%prime[i] == 0) temp/=prime[i], ans++;
        if(ans > 0) res=res*(ans+1);
    }
    if(temp>1) res *= 2;

    return res;
}
int main()
{
    int t,cas=1;
    Prime();

    scanf("%d",&t);
    while(t--)
    {
        ll num;
        scanf("%lld",&num);
        printf("Case %d: %lld\n",cas++,Factorization(num)-1);
    }
    return 0;
}
