
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    string s;
    cin >>t;

    getline(cin,s);
    int a[200];
    while(t--)
    {
         int i=0;
         getline(cin,s);
         istringstream t1(s);
         while(t1>>a[i]) i++;
         int maxi=0;
         for(int j=0; j<i; j++)
         {
             for(int k=j+1; k<i; k++)
             {
                maxi=max(maxi,__gcd(a[j],a[k]));
             }
         }

         cout <<maxi<<endl;
    }

    return 0;
}
