#include<bits/stdc++.h>
#define phi acos(-1)
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        double R;
        int n;
        scanf("%lf %d",&R,&n);
        double th=sin(phi/n);
        R=R*th/(th+1);
        if(fmod(R,1)>0.0) printf("Case %d: %.10f\n",cas++,R);
        else printf("Case %d: %.0f\n",cas++,R);
    }
    return 0;
}
