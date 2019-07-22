
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll value[100];
void  Store()
{
    value[0]=0;
    value[1]=2;
    value[2]=3;
    for(int i=3; i<=60; i++) value[i]= value[i-1]+value[i-2];

}
int main()
{
    int t,cas=1;
    Store();
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        printf("Scenario #%d:\n%lld\n\n",cas++,value[n]);
    }
    return 0;
}
