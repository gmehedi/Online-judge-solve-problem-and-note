

#include<bits/stdc++.h>
#define maxi 100000000
using namespace std;
bool b[maxi+2];

void Prime()
{
    b[0]=false;
    b[1]=false;
    for(int i=2; i*i<=maxi; i++) if(b[i]) for(int j=i+i; j<=maxi; j=j+i )b[j]=false;
}

bool Check(int temp)
{
    for(int i=temp/2; i>=0; i--)
    {
        if( b[ temp-i ]&& i != temp-i && b[i] ) { printf("%d is the sum of %d and %d.\n",temp,i,temp-i); return 1; }
    }
    printf("%d is not the sum of two primes!\n",temp);
}

int main()
{
    memset(b,true,sizeof b);
    Prime();
    int n;
    while( scanf("%d",&n) != EOF)
    {
        if(n<5 )printf("%d is not the sum of two primes!\n",n);
        else
        {
            if(n%2)
            {
                if(b[n-2]) printf("%d is the sum of %d and %d.\n",n,2,n-2);
                else printf("%d is not the sum of two primes!\n",n);
            }
            else Check(n);
        }
    }
    return 0;
}
