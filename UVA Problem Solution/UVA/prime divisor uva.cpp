#include<bits/stdc++.h>
#define N 10000100
using namespace std;
int64_t prime[N];
bool sign[N];
void Seive()
{
    int64_t t= sqrt(N);
    sign[0]==true;
    sign[1]==true;

    for(int64_t i=3; i<=t; i+=2)
    {
        if(!sign[i])
        {
            for(int64_t j=i*i; j<=N; j=j+i*2)
            {
                sign[j]=true;
            }
        }
    }
    int64_t k=1;
    prime[0]=2;

    for(int64_t i=3; i<=N; i+=2)
    {
        if(!sign[i])prime[k++]=i;
    }
}
int main()
{
    int long long n,maxi=0;
    memset(sign,false,sizeof sign);
    sign[0]=false;
    sign[1]=false;
    Seive();
    while(cin >>n)
    {
        if(n==0)return 0;
        if(n<0)n*=-1;

        int cnt=0;
        for(int64_t i=0; prime[i]*prime[i]<=n; i++)
        {
      //  cout <<"P  "<<prime[i]<<endl;
            bool b1=true;

            while(n%prime[i]==0)
            {
                if(b1)
                {
                    cnt++;
                    b1=false;
                }
                maxi=prime[i];
                n=n/prime[i];


            }
        }
        if (n != 1) {
            maxi = n;
            cnt++;
        }
        if(cnt<2)
        {
            cout <<"-1"<<endl;
        }
        else
        cout <<maxi<<endl;


        }

   return 0;

}
