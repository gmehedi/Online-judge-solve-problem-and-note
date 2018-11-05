#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 10000000
using namespace std;
int prime[1000000],k;
bitset<maxi>b;
ll n;
void Prime()
{
    b[0]=true;
    for(int i=3; i*i<=maxi; i+=2) if(!b[i]) for(int j=i*i; j<=maxi; j=j+(i*2) )b[j]=true;
    k=1;
    prime[0]=2;
    for(int i=3; i<=maxi; i+=2)if(!b[i] ) prime[k++]=i;
    //for(int i=0; i<100; i++) cout<<prime[i]<<endl;
}

ll Solve()
{
    ll temp=n,ans=1;
    for(int i=0; prime[i]*prime[i] <= n && i<k; i++)
    {
        ll cnt=0;
        if(temp%prime[i] == 0)
        {
            while(temp%prime[i] == 0) temp/=prime[i], cnt++;
            ans *= (cnt+cnt+1); //total pair count each take multiple times without num1 == num2 like as  { (2^0,2^1) (2^1,2^0),(2^1,2^1)}
            if(temp < prime[i]) break;
        }
    }
    if(temp>1) ans=ans*3;
    return (ans/2)+1;
}
int main()
{
    int t,cas=1;
    Prime();

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",cas++,Solve() );
    }
    return 0;
}

