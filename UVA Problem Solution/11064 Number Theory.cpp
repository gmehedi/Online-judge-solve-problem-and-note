
#include <bits/stdc++.h>
#define N 100000
using namespace std;
int64_t prime[N];
bool sign[N];
void Seive()
{
    int k=1;
    prime[0]=2;
    for(int64_t i=3; i<=N; i+=2)//2147483647
    {
        if(sign[i])
            for(int64_t j=i*i; j<=N; j+=i*2) sign[j]=false;
    }
    for(int64_t i=3; i<=N; i+=2)
    {
        if(sign[i]) prime[k++]=i; //cout <<"I "<<prime[k-1]<<endl;}
     }

}
int Num_Of_Div(int n)
{
    int cnt,total=1;
    double total1=n;
  //if(n==1)return 1;

    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
       // cout <<"P   "<<prime[i]<<endl;
        cnt=0;
        bool b=true;
        while(n%prime[i]==0)
        {
            if(b)
            {
                total1*=( 1.00- (1.00/(double)prime[i]));
                b=false;
            }
            cnt++;
            n/=prime[i];
        }
        if(cnt>0)
        total*=(cnt+1);
    }
    if(n>1)
    {
         total1*=( 1.00- (1.00/(double)n));
        total*=2;
    }
  // cout <<"T  "<<t<<endl;
   return total+(int)total1;

}

int main()
{
    memset(sign,true,sizeof sign);
    Seive();
    int n;
    while(scanf("%d",&n) != EOF)
    cout <<n-(Num_Of_Div(n)-1)<<endl;

}
