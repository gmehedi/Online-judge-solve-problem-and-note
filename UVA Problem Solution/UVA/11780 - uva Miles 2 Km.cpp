
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

int main()
{
    ll n;
    while( scanf("%lld",&n) && n )
    {
       double des=(1.6*n);
       double maxi=ceil(n*1.6),mini=floor(n*1.6);
        printf("%.2f\n",min(fabs(des-maxi),fabs(des-mini)));
    }

    return 0;
}
