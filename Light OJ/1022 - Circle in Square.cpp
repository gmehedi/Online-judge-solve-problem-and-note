

#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        double r;
        scanf("%lf",&r);
        double ta=pi*(r*r);
        double ra=(r*2)*(r*2);
        printf("Case %d: %.2f\n",cas++,ra-ta);
    }
    return 0;
}
