
#include<bits/stdc++.h>
using namespace std;

long long cat[35]={0},supercat[35]={0};

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

void Supcat()
{
    supercat[3]=3;
    supercat[1]=1;
    supercat[2]=1;
    for(int num=4; num<=30; num++)
    {
        supercat[num]=( ( (6*num-9)*supercat[num-1] - (num-3)*supercat[num-2] )/num);
    }

}
int main()
{

    cat[0]=1;
    Catalan();
    Supcat();
    int n;
    while( scanf("%d",&n) != EOF )
    {
        printf("%lld\n",supercat[n]-cat[n-1]);
    }

    return 0;
}
