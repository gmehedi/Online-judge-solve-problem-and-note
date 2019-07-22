
#include<bits/stdc++.h>
using namespace std;
long long Big_mod(long long n,long long r)
{
    long long x=1;
//    cout<<"T  "<<n<<"   "<<r<<endl;
   for(int i=n; i>r; i--)
   {
       x=x*i;
      // cout<<"D  "<<x<<endl;
       while(x%10==0)x/=10;
       x%=10000000000;
     //  cout<<"T  "<<x<<endl;
   }
   return x%10;
}
int main()
{
    long long n,p;
    while(cin>>n>>p)
    {
        long long r=n-p;
        cout<<Big_mod(n,r)<<endl;
    }
    return 0;
}
