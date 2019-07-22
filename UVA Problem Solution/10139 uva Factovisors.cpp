#include<bits/stdc++.h>
using namespace std;
bool Isdivide(long long n,long long m, int cnt)
{
    int cnt2=0;
   long long t=m;
    while(n/t)
    {
      //  cout<<"G  "<<n<<"  "<<t<<endl;
        cnt2+=(n/t);
        t=m*t;
    }
//    cout<<cnt<<"  "<<cnt2<<endl;

    return cnt<=cnt2;
}
bool   PrimeFactorization(long long n,long long m)
{
    long long i,h=m;
    for( i=2; i*i<=h; i++)
    {
        int cnt=0;
        while(m%i==0)
        {
            cnt++;
            m/=i;
        }
        if(cnt>0)
        if( !Isdivide(n,i,cnt) )
        {
            return false;
        }
    }
    if(m>1)
    {
        if( !Isdivide(n,m,1) )
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long n,m;
   // cout<<Isdivide(10,2,1)<<endl;
   // cout<<"F"<<endl;
    while( scanf("%lld %lld",&n,&m)==2)
    {
        //cout<<n<<"  "<<m<<endl;

        if( PrimeFactorization(n,m) && m!=0)
        {
            printf("%lld divides %lld!\n",m,n);
        }
        else printf("%lld does not divide %lld!\n",m,n);
    }

    return 0;
}
