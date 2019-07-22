


#include<bits/stdc++.h>
#include<algorithm>
#define N 10000000
using namespace std;
long long prime[1000000],sign[N],n;
void Seive()
{
    for(int i=3; i*i<=N; i+=2)
    {
        if(sign[i])
        {
             for(int j=i*i; j<=N; j+=i*2)
             {
                 sign[j]=false;
             }
        }

     }
     prime[0]=2;
     int k=1;
     for(int i=3; i<=N; i+=2) if(sign[i])prime[k++]=i;

}
int  main()
{
    memset(sign,true,sizeof sign);
    Seive();
    while(cin>>n && n!=0)
    {
        double t=n;
        for(int i=0; prime[i]*prime[i]<=n; i++)
        {
            bool b= true;
            while(n%prime[i]==0)
            {
                if(b)
                {
                    t=t*(1.00-(1.00/(double)prime[i]) );
                    b=false;
                }
                n=n/prime[i];

            }
        }
        if(n>1)t*=(1.00-(1.00/(double)n));

        cout <<(int)t<<endl;
    }

    return 0;
}
