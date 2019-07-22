
#include<bits/stdc++.h>
using namespace std;
long long Digit(long long temp, long long base)
{
    double t=0;
    for(int i=1; i<=temp; i++) t+=log(i)/log(base);
    return floor(t)+1;
}
//find the maximum power of base  that divides N! like as Zero()
long long Zero(long long temp,long long base)
{
    long long n=base,mini=INT_MAX,number=temp;
    for(int i=2; i<=n; i++)
    {
        long long cnt=0,fac=0;
       // cout<<"H  "<<i<<"   "<<base%i<<endl;
        if(base%i==0)
        {
            while(base%i==0) cnt++,base/=i;
            long long k=i,d=number;
            //while(d/i>0) fac+=(d/i),d/=i; //also use it for factor
            while( number>=k )fac+=number/k,k*=i;
            mini=min(mini,fac/cnt);
        }
    }
    if(mini==INT_MAX)mini=0;
    return mini;
}

int main()
{
    long long f,b;
    while( scanf("%lld %lld",&f,&b) != EOF )
    {
        printf("%lld %lld\n",Zero(f,b),Digit(f,b));
    }
    return 0;
}
