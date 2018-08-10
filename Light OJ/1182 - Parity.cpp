#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int num;
        scanf("%d",&num);
        int one = __builtin_popcount(num);
        if(one%2==0)printf("Case %d: even\n",cas++);
        else printf("Case %d: odd\n",cas++);
    }
    return 0;
}
