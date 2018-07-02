
#include<bits/stdc++.h>
#define N 200000000
using namespace std ;
long long a[N];
int main ()
{
 //  memset(a,0,sizeof a);
    for(int64_t i=3;i<=sqrt(N); i+=2)
    {
        if(a[i] == 0)
        {
               for(int64_t j=i*i; j<=N; j=j+2*i)
               {
                   a[j]=1;
               }
        }

    }
  long long s,l;
  scanf("%lld %lld",&s,&l);
  if(s<=2)
    cout <<"2"<<endl;
    for(int64_t i=s; i<=l; i+=2)
    {
        if(a[i]==0)
            cout <<i<<endl;
    }


}
