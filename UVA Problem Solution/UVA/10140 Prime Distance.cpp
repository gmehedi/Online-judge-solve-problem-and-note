#include<bits/stdc++.h>
# define N 2147483647
# define sqt 1000100
using namespace std;
struct subject
{
    long long d;
    long long  a;
    long long b;
};

//bool compare1(subject x,subject y) { return x.d < y.d; }

//bool compare2(subject x,subject y) { return x.d > y.d; }

vector<subject>v1;

long long prime[sqt],seg[sqt];
bool sign[sqt];

void sieve()
{
    prime[0]=2;
    for(int i=3; i*i<=sqrt(N); i+=2)
    {
        if(sign[i])
        {
            for(int j=i*i; j<=sqrt(N); j+=i*2 )
            {
                sign[j]=false;
            }
        }
    }
    int k1=1;
    for(int i=3; i<=sqrt(N); i+=2)if(sign[i])prime[k1++]=i;
    prime[k1++]=INT_MAX;
}
long long k=0,maxi=INT_MIN,c1,c2,d1,d2,u,v,mini=INT_MAX;

void seg_sieve()
{

    for(int64_t i=0; prime[i]*prime[i]<=v; i++)
    {
        int64_t base=(u/prime[i])*prime[i];
   //     cout<<"B "<<base<<"   "<<prime[i]<<endl;
        if(base<u) base+=prime[i];
       // cout<<"B!  "<<base<<"      "<<endl;
        for(int64_t j=base; j<=v; j+=prime[i])
        {
         //   cout<<"J  "<<j<<"          "<<v<<endl;
            sign[j-u]=false;
        }
        if(base==prime[i])sign[base-u]=true;
    }

    for(int64_t i=u; i<=v; i++)
    {
      //  cout<<"U   "<<i-u<<endl;
        if(sign[i-u])
        {
            seg[k++]=i;
        }

    }

     for(int i=0; i<k-1; i++) v1.push_back({abs(seg[i]-seg[i+1]),seg[i],seg[i+1]});


}

int main()
{
    memset(sign,true,sizeof sign);
    sieve();

    while( scanf("%lld%lld",&u,&v) != EOF)
    {
      //  cout<<"M "<<INT_MAX<<endl;
        if(u==INT_MAX)
        {
            printf("There are no adjacent primes.\n");
            continue;
        }
         memset(sign,true,sizeof sign);
         maxi=INT_MIN;
         c1=0,c2=0,d1=0,d2=0,k=0;
         if(u==1)u++;

         seg_sieve();

         maxi=v1[0].d;
         mini=v1[0].d;
         c1=v1[0].a;
         c2=v1[0].b;
         d1=v1[0].a;
         d2=v1[0].b;

         for(int64_t i=0 ;i<(int)v1.size(); i++)
        {

             if(maxi<v1[i].d)
             {
                 maxi=v1[i].d;
                d1=v1[i].a;
                d2=v1[i].b;
            }
            if(mini>v1[i].d)
            {
                mini=v1[i].d;
                c1=v1[i].a;
                c2=v1[i].b;
            }

      }
      if(k<2)printf("There are no adjacent primes.\n");
      else printf("%lld,%lld are closest, %lld,%lld are most distant.\n",c1,c2,d1,d2);

      v1.clear();

    }


    return 0;
}
