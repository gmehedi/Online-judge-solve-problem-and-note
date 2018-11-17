

#include<bits/stdc++.h>
#define ll long long
#define maxl 10000010
using namespace std;



ll Solve(ll d, ll n)
{
    ll temp=n,cnt=0;
    ll digit= (ll)log10(n);
    digit++;

    while(1)
    {
        cnt++;
        n=n%d;
       // cout<<"N!  "<<n<<endl;
        if(n == 0) return cnt;
        n = ((n*10)+temp) ;
       // cout<<"N "<<n<<endl;
    }
}
int main()
{
    int t,cas=1;

    scanf("%d",&t);

    while(t--)
    {
        ll n,d;
        scanf("%lld %lld",&n,&d);
        printf("Case %d: %lld\n",cas++,Solve(n,d));
    }

    return 0;
}
