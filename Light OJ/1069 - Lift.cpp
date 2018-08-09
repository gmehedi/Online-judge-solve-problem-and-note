
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int me,lift;
        scanf("%d %d",&me,&lift);
        long long ans= (abs(me-lift)+me)*4+19;
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}
