
#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long n,r;
   scanf("%lld%lld",&n,&r);
   long long maxi=0;
   long long a[n+2];
   for(int i=0; i<n; i++) scanf("%lld",&a[i]) ,maxi=max(a[i],maxi);
   long long  low=0, high=maxi,cutting_point=0,res=0;

   while(high>=low)
   {
       long long total=0;
       cutting_point= (high+low)/2;
    //cout<<"G   "<<cutting_point<<endl;
       for(int i=0; i<n; i++)
       {
           if(cutting_point>=a[i])continue;
           if(cutting_point<a[i])total+=abs(a[i]-cutting_point);
       }
    //  cout<<"T  "<<total<<endl;


       if(total<r) high=cutting_point-1;
       else if(total>r) low=cutting_point+1, res=max(res,cutting_point);
       else { res=cutting_point; break; }
     //  cout<<"K  "<<low<<"   "<<high<<endl;
   }
 //  cout<<"F  "<<cutting_point<<endl;
   printf("%lld",res);
    return 0;
}
