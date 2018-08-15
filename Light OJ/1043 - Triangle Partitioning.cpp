#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        double ab,bc,ac,ade_by_bcde;
        scanf("%lf %lf %lf %lf",&ab,&bc,&ac,&ade_by_bcde);

        double ratioo= ade_by_bcde/(ade_by_bcde+1);
        ratioo=sqrt(ratioo);
        printf("Case %d: %.8f\n",cas++,ab*ratioo);
    }
    return 0;
}
