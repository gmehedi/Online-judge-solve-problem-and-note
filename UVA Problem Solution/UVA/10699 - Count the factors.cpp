
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t=0,cnt=0;
    while(cin >>n && n)
    {
        t=n;
        cnt=0;
        bool b=true;
        while(t%2==0)
        {
            if(b)cnt++;
            b=false;
            t/=2;
        }
        for(int i=3; i<sqrt(t); i+=2)
        {
            b=true;
            while(t%i==0)
            {
                if(b)cnt++;
                b=false;
                t/=i;

            }

        }
        if(t>2)cnt++;
        printf("%lld : %lld\n",n,cnt);


    }

    return 0;
}
