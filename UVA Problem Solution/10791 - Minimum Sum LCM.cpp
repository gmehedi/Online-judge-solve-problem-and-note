
#include<bits/stdc++.h>
#include<algorithm>
#define N 10000000
using namespace std;

long long n,prime[10000000],sum=0,cas=0,mini,sign[N];

void Seive()
{
    int cnt=0;
    int k=1;
    prime[0]=2;
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
    for(int i=3; i<=N; i+=2)
    {
        if(sign[i])
        {
            cnt++;
            prime[k++]=i;
          //  cout <<prime[k-1]<<endl;
        }
    }


}

int main()
{
    memset(sign,true,sizeof sign);
    Seive();
    while( cin >>n && n !=0 )
    {
        if(n==1)
        {
            printf("Case %lld: 2\n",++cas);
            continue;
        }
        long long num=n;
        sum=0;
        long long t;
        bool c=true;
        int d=0;
        for(long long i=0; prime[i]*prime[i]<=n; i++)
        {
              t=1;
              c=true;
           //   cout <<"H "<<prime[i]<<"  "<<n%prime[i]<<endl;
              while( !(n%prime[i]) )
              {
                  if(c)
                  {//cout <<"H "<<prime[i]<<"  "<<n%prime[i]<<endl;
                      d++;
                      c=false;
                  }
                  t*=prime[i];
                  n=n/prime[i];
                //  cout <<"p  "<<prime[i]<<endl;
              }
              if(t != 1)
              {
                   sum+=t;
              }

        }
//cout <<"D  "<<d<<endl;
        if(n>1)sum+=n,d++;

        if(d>=2)printf("Case %lld: %lld\n",++cas,sum);
        else printf("Case %lld: %lld\n",++cas,num+1);

    }
    return 0;
}
