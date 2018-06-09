
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    memset(dp,-1,sizeof dp);
    while( getline(cin,s) )
    {

       fib[0]=1;
       fib[1]=2;
        Fib(100);
        for(int i=0; i<100; i++)cout<<fib[i]<<"  ";
    }

    return 0;
}
