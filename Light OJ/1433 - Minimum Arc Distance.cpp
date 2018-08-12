
#include<bits/stdc++.h>
using namespace std;

double Distance(double x1, double y1, double x2, double y2)
{
    return sqrt( powl(x2-x1,2)  + powl(y2-y1,2) );
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        double o1,o2,x1,x2,y1,y2;
        scanf("%lf %lf %lf %lf %lf %lf",&o1,&o2,&x1,&y1,&x2,&y2);
        double oa=Distance(o1,o2,x1,y1);
        double ob=Distance(o1,o2,x2,y2);
        double ab=Distance(x1,y1,x2,y2);

      //  cout<<"A  "<<oa<<"  "<<ob<<"   "<<ab<<endl;

        double angle= ( (oa*oa)+(ob*ob)-(ab*ab) )/(2*oa*ob);
        angle=acos(angle);
       // cout<<"A  "<<angle<<endl;
        double res=(oa*angle);
        printf("Case %d: %f\n",cas++,res);
    }
    return 0;
}
