
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,u,v,ans=0,power=0,maxi=0,num=0;
    cin >>t;
    while(t--)
    {
        cin >>u>>v;
        maxi=0,num=0,power=0,ans=1;
        if(u==0&&v==0)
        {
            cout <<"Between 0 and 0, 0 has a maximum of 0 divisors."<<endl;
            continue;
        }
         if(u==1&&v==1 ||u==0&&v==1)
          {
              cout <<"Between 1 and 1, 1 has a maximum of 1 divisors."<<endl;
              continue;
         }

        for(long long i=u; i<=v; i++)
        {
            long long t=i;
            ans=1,power=0 ;
            while(t%2==0)
            {
                power++;
                t/=2;
            }
           // cout <<"P  "<<power<<"T         "<<t<<"I!  "<<i<<endl;
            if(power>0)
            {
                ans*=(power+1);
            }
              //      cout <<"A        "<<ans<<endl;
            for(long long  j=3; j<=sqrt(t); j+=2)
            {
                power=0;
                while(t%j==0)
                {
                    power++;
                    t/=j;
                }
                 // cout <<"P11  "<<power<<"T         "<<t<<"I         "<<i<<endl;
                if(power>0)
                    ans*=(power+1);

            }
            if(t>2)ans*=2;

            if(maxi<ans)
            {
                maxi=ans;
                num=i;
            }

        }

        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",u,v,num,maxi);
    }
    return 0;
}
