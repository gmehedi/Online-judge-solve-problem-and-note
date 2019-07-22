
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while( scanf("%d",&n) != EOF )
    {
        if(n<0 && n%2 ) { printf("Overflow!\n"); continue; }
        long long ans=1;
        bool b=false;
        for(long long i=2; i<=n; i++)
        {
            ans*=i;
            if(ans>6227020800){ printf("Overflow!\n"); b=true; break; }
        }
        //cout<<"B  "<<b<<endl;

        if( ans<10000 && !b ){  printf("Underflow!\n"); }
        else if( !b ) printf("%lld\n",ans);


    }
    return 0;
}
