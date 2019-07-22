

#include <bits/stdc++.h>
#define ll long long
#define ull long long
#define maxl 10000
using namespace std;
ll dp[60];
void Store()
{
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=50; i++) dp[i]=dp[i-1]+dp[i-2];
}
int main()
{
    int n;
    Store();
    while(scanf("%d",&n) && n)
    {
        printf("%lld\n",dp[n]);
    }
    return 0;
}
