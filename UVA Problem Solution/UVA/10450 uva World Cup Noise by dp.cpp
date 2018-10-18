
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100];
int n;

ll  solve(int pos)
{
    if(pos<0) return 0;
    if(pos == 0) return 1;
    if(dp[pos] != -1) return dp[pos];
    ll cnt=0;

    cnt+=solve(pos-2);
    cnt+=solve(pos-1);

    return dp[pos]=cnt;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    memset(dp,-1,sizeof dp);
    while(t--)
    {
        scanf("%d",&n);
        if( n==0 ){ printf("Scenario #%d:\n%lld\n\n",cas++,0); }
        else printf("Scenario #%d:\n%lld\n\n",cas++,solve(n+1));
    }
    return 0;
}
