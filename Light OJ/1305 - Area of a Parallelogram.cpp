
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int ax,ay,bx,by,cx,cy,dx,dy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=cx;
        dy= ay+(cy-by);
        dx=ax+(cx-bx);
        double q=( (ax*by)+(bx*cy)+(cx*dy)+(dx*ay) )-( (ay*bx)+(by*cx)+(cy*dx)+(dy*ax) );
        q= 0.5*q;
        int res=(int)q;
        printf("Case %d: %d %d %d\n",cas++,dx,dy,abs(res));
    }
    return 0;
}
