
// C++ implementation of Naive method to print all
// divisors
#include <bits/stdc++.h>
#define ll long long
#define ull long long
#define maxl 10000
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ull tm=0,x=1,y=0,z=0;
        bool b1=true,b2=false,b3=false;

        for(int i=0; i<n; i++)
        {
            if(tm == 2 && b1 ) y=x,x=0,z=0,tm=0, b1=false, b2=true, b3=false;
            if(tm == 2 && b1 ) y=x,x=0,z=0,tm=0, b1=false, b2=true, b3=false;
            if(tm == 8 && b2 ) z=y,y=0,x=0,tm=0, b1=false,b2=false,b3=true;
            if(tm == 16 && b3 ) x= (z*2), y=0, z=0, b1=true,b2=false,b3=false,tm=0;
            tm++;
        }
        printf("%lld %lld %lld\n",x,y,z);
    }
    return 0;
}
