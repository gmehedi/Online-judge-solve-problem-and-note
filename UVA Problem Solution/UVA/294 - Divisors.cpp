
#include<bits/stdc++.h>
#define N 20000000
using namespace std;
int main()
{

    int64_t u,v,ans=0,num=0,power=0,t;

    cin >>t;

    while(t--)
    {
        cin >>u>>v;
        int maxi=0,divisor=0;
        bool b=false;

        for(int i=u; i<=v; i++)
        {
            ans=1;
            power=0;
            int t=i;

                while(t%2==0)
                {
                    t=t/2;
                    power++;
                    b=true;
                }
                if(power>0)
                ans*=(power+1);

                for(int k=3; k*k<=t; k+=2)
                {
                    power=0;
                    while(t%k==0)
                    {
                        b=true;
                        t=t/k;
                        power++;

                    }
                    if(power>0)ans*=(power+1);

            }
            if(t>2)ans*=2;

            if(ans>maxi &&b)
            {
                maxi=ans;
                num=i;
            }
        }


        printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n",u,v,num,maxi);
     }

    return 0;
}
