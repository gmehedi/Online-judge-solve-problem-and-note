
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxi 50000
#define mod 1000000007
using namespace std;
ll NumberOfDigit(ll n)
{
    ll cnt=0,tt=5;
    while(1)
    {
        ll temp = n/tt;
       // cout<<"T  "<<temp<<endl;
        if(temp == 0) break;
        cnt+=temp;
        tt = tt*(ll)5;
    }
    return cnt;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        ll n;
        scanf("%lld",&n);

        ll left=1,right=1e18+2;
        ll ans=0;

        while( (right-left) > 0)
        {
            ll mid = (left+right)/2;

            ll digit= NumberOfDigit(mid);

            if(digit >= n ) right=mid;
            else left=mid+1;
            if(n == digit) ans=mid;
           // cout<<"M  "<<mid<<"  "<<digit<<endl;
        }
        if(ans == 0) printf("Case %d: impossible\n",cas++);
        else printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
