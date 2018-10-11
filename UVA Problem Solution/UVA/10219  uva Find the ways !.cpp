
#include<bits/stdc++.h>
using namespace std;

long long mod= 1000000007;
long long Solve(long long n, long long k)
{
    if( (n-k)<k ) k=n-k;
    long long temp=1,cnt=0;
    for(int i=1; i<=k; i++)
    {
      //  cout<<"H "<<i<<" "<<n-k+1<<" "<<n<<endl;
       temp=temp*(n-k+i)/i;
       while( (temp/100) != 0) temp/=10,cnt++;
    }
    while(temp)
    {
        temp/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    long long n,k;
    while( scanf("%lld %lld",&n,&k) == 2)
    printf("%lld\n",Solve(n,k));
    return 0;
}
