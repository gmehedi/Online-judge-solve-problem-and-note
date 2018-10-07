
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while( t-- )
    {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int tt= (a+b)/k;
        if(tt%2 != 0) printf("COOK\n");
        else printf("CHEF\n");
    }

    return 0;
}
