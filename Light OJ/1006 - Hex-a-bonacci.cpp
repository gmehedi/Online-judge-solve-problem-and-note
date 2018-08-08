
#include<bits/stdc++.h>
#define mod 10000007
using namespace std;

int a, b, c, d, e, f;


long long result(long long n)
{
    long long res[10010]={0};
    if(n<=5)
    {
        if( n == 0 ) return a;
        if( n == 1 ) return b;
        if( n == 2 ) return c;
        if( n == 3 ) return d;
        if( n == 4 ) return e;
        if( n == 5 ) return f;
    }
    else
    {
        res[0]=a, res[1]=b, res[2]=c, res[3]=d, res[4]=e, res[5]=f;
        for(int i=6; i<=n; i++)
        {
            res[i]= (res[i-1]+res[i-2]+res[i-3]+res[i-4]+res[i-5]+res[i-6]) %mod;
        }
        return res[n]+mod%mod;
    }
}
int main() {
    long long n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, result(n) % mod);
    }
    return 0;
}
