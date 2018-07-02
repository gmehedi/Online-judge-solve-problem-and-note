#include<stdio.h>
#include<math.h>
#include<string.h>
#include<bits/stdc++.h>
#define N 20000000

using namespace std;

bool cnt[N];
long long int tp[N];


void Sieve()
{
    for(int64_t i=3; i*i<=N; i+=2)
    {
        if(!cnt[i])
        {
             for(int64_t j=i*i; j<=N; j=j+2*i)
            {
                cnt[j]=true;
            }
        }

    }
    int64_t t=1;

      for(int i=3; i<=N; i+=2)
        {
            if(!cnt[i] && !cnt[i+2])
            {
              tp[t++]=i;
             // cout <<"I  "<<i<<endl;
            }

        }

}

int main()
{
    int n;
    memset(cnt,false,sizeof cnt);
    Sieve();

        while(cin >>n)
        {
            int t=tp[n];
            printf("(%d, %d)\n",t,(t+2)) ;
        }


    return 0;
}
