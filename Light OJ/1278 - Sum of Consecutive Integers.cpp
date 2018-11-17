
#include<bits/stdc++.h>
#define ll long long
#define maxl 10000010
using namespace std;

ll prime[664579+4],k=0;
bool sign[maxl+1110];

void Prime()
{
    prime[k++]=2;
    memset(sign,true,sizeof sign);

    for(ll i=3; i*i<=maxl; i+=2)
    {
        for(ll j=i*i; j<=maxl; j+=(i*2)) if(sign[j]) sign[j]=false;
    }
    for(ll i=3; i<=maxl; i+=2) if(sign[i]) prime[k++]=i;

   // for(int i=0; i<k; i++) cout<<"I  "<<i<<"  "<<prime[i]<<endl;

  //  cout<<"K  "<<k<<endl;
}

ll Solve(ll n)
{
    ll temp;

    while(n%2 == 0) n=n/2;

    temp=n;
    ll cnt=0,ans=1;

    for(ll i=0; prime[i]*prime[i]<=n && i<k; i++)
    {
        cnt=0;
        if(temp%prime[i] == 0)
        {
            while(temp%prime[i] == 0) temp /= prime[i], cnt++;
            ans=(ans*(cnt+1));
        }
        if(temp<prime[i]) break;
    }
    if(temp>1) ans *= (ll)2;

    return (ans-(ll)1); //  single sequence is not allowed ...
}
int main()
{
    int t,cas=1;
    Prime();

    scanf("%d",&t);

    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cas++,Solve(n));
    }

    return 0;
}
