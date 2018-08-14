

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,c;
        scanf("%lf %lf %lf",&a,&b,&c);
        double r1=a+b, r2=b+c, r3=a+c;
        double s=(r1+r2+r3)/2;
        //find the area of triangle
        double triangle_area = sqrt( s*(s-r1)*(s-r2)*(s-r3) );
        //find the all angles of triangle for find the arc area
        double angle_a= ( (r3*r3)+(r2*r2)-(r1*r1) )/(2*r2*r3);
        double angle_b=( (r3*r3)+(r1*r1)-(r2*r2) )/(2*r1*r3);
        double angle_c=( (r1*r1)+(r2*r2)-(r3*r3) )/(2*r1*r2);
        //convert degre -1 --- +1 to 0-----180
        angle_a = acos(angle_a);
        angle_b = acos(angle_b);
        angle_c = acos(angle_c);

        double res= ( (angle_a*c*c) + (angle_b*a*a) + (angle_c*b*b) )/2.00;
        res= triangle_area-res;
        printf("Case %d: %.10f\n",cas++,res);
    }
    return 0;
}
