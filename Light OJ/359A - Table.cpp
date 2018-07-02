

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
   cin >>n>>m;
   int a[n+1][m+1];

   for(int i=0; i<n; i++)
   for(int j=0; j<m; j++)
   {
       cin >>a[i][j];
   }

   for(int j=0; j<m; j++)
   {
       if( a[0][j]==1 || a[n-1][j]==1)
       {
           cout <<"2"<<endl;
           return 0;
       }

   }
    for(int j=0; j<n; j++)
   {
       if( a[j][0]==1 || a[j][m-1]==1)
       {
           cout <<"2"<<endl;
           return 0;
       }

   }

   cout <<"4"<<endl;

    return 0;
}
