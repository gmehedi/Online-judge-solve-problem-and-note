

#include<bits/stdc++.h>
using namespace std;
double p, q, r, s, t,u;
double Fun(double x)
{
   return p*exp(-1*x) + q*sin(x) + r*cos(x) + s*tan(x)+t*(x*x)+u;
  //  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;

}
double Bisection()
{
    double low=0.0,high=1.0;
    if(Fun(0)*Fun(1)>0) { printf("No solution\n"); return 0; }
    double ebs=0.0000001,mid;
    while(fabs(high-low)>ebs)
    {
        mid=(high+low)/2;
        if(Fun(mid)*Fun(low)>0) low=mid;
        else high=mid;
    }
    printf("%.4f\n",mid);
}
int main()
{
   while( cin>>p>>q>>r>>s>>t>>u ) Bisection();
    return 0;
}
