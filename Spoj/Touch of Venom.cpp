
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long h,p,a,cnt=1,cas;
    scanf("%lld",&cas);
    while( cas-- )
    {
        scanf("%lld %lld %lld",&h,&p,&a);
        if(h<=p)
        {
            printf("1\n");
            continue;
        }
        double n= -1*(p-(2*a));
        double m= (p-(2*a))*(p-(2*a));
        double o=(8*p*(a-h));
        m=sqrt(m-o);
        long long res= n=ceil ((n+m)/(2*p));
        res=res+(res-1);
        printf("%lld\n",res);
    }
    return 0;
}
