#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   int a[1100],dif[1100];
   while( getline(cin,s) )
   {
       if(s[0]=='0')break;

       stringstream ss(s);
       int i=0,k=0;
       while(ss>>a[i++])
       {
           if(i>=2 && a[i-1]!=0)
           {
               dif[k++]=(a[i-1]-a[i-2]);
           }
       }
       if(k<2)
       {
           printf("%d\n",abs(dif[0]));
           continue;
       }
       int ans=__gcd(dif[0],dif[1]);
       for(int j=2; j<k; j++)
       {
           ans=__gcd(ans,dif[j]);
       }

       printf("%d\n",abs(ans));
   }

    return 0;
}
