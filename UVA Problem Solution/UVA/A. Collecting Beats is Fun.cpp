
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >>k;
    char c;
    int cnt[20]={0};

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
               cin >>c;
               cnt[c-48]++;
        }


    int t=k*2;

     for(int i=0; i<20; i++)
     {
         if(cnt[i]>t)
         {
             cout <<"NO"<<endl;
             return 0;
         }

     }

     cout <<"YES"<<endl;



    return 0;
}
