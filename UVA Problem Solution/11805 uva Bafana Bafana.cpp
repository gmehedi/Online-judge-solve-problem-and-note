
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,k,p,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&p);
        int temp=k+p;
        if(temp>n)temp%=n;

        printf("Case %d: %d\n",cas++,temp==0?n:temp);
    }
    return 0;
}
