
#include<bits/stdc++.h>
#define N 100000
using namespace std;
bool b[100010];
long long prime[40000];
int k=1;
void Prime()
{
    for(int i=3; i*i<=N; i+=2)
    {
        if(b[i])
        {
            for(int j=i*i; j<=N; j=j+(i*2) )
            {
                b[j]=false;
            }
        }
    }
    prime[0]=2;
    for(int i=3; i<=N; i+=2)if(b[i])prime[k++]=i;
    prime[k++]=INT_MAX;
    //cout<<"K  "<<k<<endl;
}

int countt(long long temp1)
{
    long long sum1=0;
     while(temp1)
    {
        sum1+=temp1%10;
        temp1/=10;
    }
    return sum1;
}

int Fun(long long temp)
{
    long long res=temp,sum1=0,sum2=0;
    bool b=false;
    sum1=countt(res);//cout<<"T  "<<sum1<<endl;
    for(int i=0; prime[i]*prime[i]<=res; i++)
    {
        long long cnt=0;
        while(temp%prime[i]==0)
        {
            temp/=prime[i];
            cnt++;
            b=true;
         }
         sum2+=cnt*countt(prime[i]);
    }//cout<<"M  "<<sum2<<endl;
    if(temp>1)
    {
        sum2+=countt(temp);
    }
    //cout<<"S2         "<<sum2<<"          "<<sum1<<"               "<<temp<<endl;
    if( sum1==sum2 && b )
    {
        printf("%lld\n",res);
        return 1;
    }
    return 0;
}
int main()
{
   long long t;
   memset(b,true,sizeof b);
   Prime();
   while( scanf("%lld",&t)!=EOF )
   {
       while(t--)
       {
           long long t1;
           cin>>t1;
            while(1)
            {
                t1++;
                if(Fun(t1))break;
            }
       }
   }

return 0;
}
