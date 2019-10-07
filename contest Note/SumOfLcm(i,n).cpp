

#include <bits/stdc++.h>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <iostream>
#define vpii vector< pair<int,int> >
#define vi vector<int>

#define for0(i,a) for(int i=0;i<a;i++)
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull              unsigned long long
#define f                first
#define s                second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define mk(x1,y1) make_pair(x1, y1)
#define maxl 1000000
#define psz 20
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
using namespace std;


ll phi[maxl + 2], prime[ (2*maxl) + 2];

ll ans[maxl + 2];

void EulersPhiSeive()
{
    for(ll i = 1; i <= maxl; i++) phi[i] = i, ans[i] = prime[i] = 0;

    phi[1] = 1;
    prime[1] = 1;

    for(ll i = 2; i <= maxl; i++)
    {
        if(!prime[i])
        {
            for(ll j = i;j <= maxl; j += i)
            {
                prime[j+i] = 1;   //all the numbers that are divisible by i are not prime
                phi[j] = (phi[j] / i) * (i-1);    //for the phi of a number n, we divide n with a prime number p such that n is divisible by p
                                            // and multiply it by (p-1), so we get the phi
            }
        }
    }

    for(int i = 1; i <= maxl; i++){
        for(int j = i ; j <= maxl; j += i){
           ans[j] += (i * phi[i]);
        }
    }
}


int main()
{
    EulersPhiSeive();
    int t;
    scanf("%d",&t);

    while(t--){
        ll n;
        scanf("%lld",&n);
        ll res = ( (ans[n] + 1LL)*n ) / 2LL;
        printf("%lld\n",res);
    }

    return 0;
}
