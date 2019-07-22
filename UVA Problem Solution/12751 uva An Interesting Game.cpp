
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&x);
        int sum=(n*(n+1) )/2;
       // cout<<"S  "<<sum<<endl;
        sum-=x;
        for(int i=1; i<k; i++)sum=sum-(i+x);
        printf("Case %d: %d\n",cas++,sum);
    }
    return 0;
}
