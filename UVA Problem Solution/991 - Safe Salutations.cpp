
#include<bits/stdc++.h>
using namespace std;

long long cat[35]={0};

long long Bionomial(int n, int k)
{
    if(k>(n-k)) k=n-k;
    long long res=1;
    for(int i=1; i<=k; i++)
    {
        res= res*(n-k+i);
        res=res/i;
    }
   return res;
}

void Catalan()
{
    for(int i=1; i<=30; i++)
    {
        long long temp=Bionomial(2*i,i);
        cat[i]=( temp/(long long)(i+1) );
    }
}


int main()
{

    cat[0]=1;
    Catalan();
    int n;
    bool b=false;
    while( scanf("%d",&n) != EOF )
    {
        if(b) printf("\n");
        b=true;
        printf("%lld\n",cat[n]);
    }

    return 0;
}
