
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        bitset<35>bit(n);
        int sz=sqrt(n)+1;

        if((long long)sz*sz != n) sz++;
        int pos=0;
        for(int i=0; i<sz; i++)
        {
            if(  ( bit.test(i) && !bit.test(i+1) ) ) { bit[i+1] = bit[i+1]^1;  bit[i] = bit[i]^1; pos=i; break; }
        }
        for(int i=0; i<pos-1; i++)
        {
            for(int j=i+1; j<pos; j++)
            {
                if(bit[j] && !bit[i])
                {
                    bit[j]=bit[j]^1;
                    bit[i]=bit[i]^1;
                }
            }
        }
        n= bit.to_ulong();
        printf("Case %d: %d\n",cas++,n);
    }
    return 0;
}
