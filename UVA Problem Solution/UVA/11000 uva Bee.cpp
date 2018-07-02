
#include<bits/stdc++.h>
# define N 200000000
using namespace std;
int main()
{
    long long n,t=1,m=0,m1;
    while(scanf("%lld",&n)==1 && n >=0 )
    {
        t=1,m=0,m1=0;
        for(int64_t i=0; i<n; i++)
        {
            m=t,t=m1+m+1,m1=m;//cout<<m1<<" "<<t<<endl;
        }
        cout<<m<<" "<<t<<endl;
    }
}
