
#include<bits/stdc++.h>
using namespace std;

struct circle
{
    double x;
    double y;
    double r;
};

vector<double>h,l;
vector<circle>v;
double distance(circle f,circle g)
{
    return ( sqrt( powl(f.x-g.x,2)+powl(f.y-g.y,2) ) );
}

void check(circle a, circle b)
{
    if(a.r<b.r) swap(a,b);

    double dis =distance(a,b);

    if(dis == (a.r+b.r)) l.push_back(0), h.push_back(a.r+dis+b.r);
    else if(dis>(a.r+b.r)) l.push_back(dis-a.r-b.r),h.push_back(dis+a.r+b.r);
    else if(dis == (a.r-b.r)) l.push_back(0),h.push_back(dis+a.r+b.r);
    else l.push_back(a.r-dis-b.r), h.push_back(a.r+b.r+dis);

}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++)
    {
        double xm,ym,rm;
        scanf("%lf %lf %lf",&xm,&ym,&rm);
        v.push_back( {xm,ym,rm} );
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            check(v[i],v[j]);
        }
    }

    sort(l.begin(),l.end());
    sort(h.begin(),h.end());

    for(int i=0; i<q; i++)
    {
        int k;
        scanf("%d",&k);

        long long ans1=upper_bound(l.begin(),l.end(),k)-l.begin();
        long long ans2=lower_bound(h.begin(),h.end(),k)-h.begin();
        ans1=(long long) abs(ans1-ans2);

        printf("%lld\n",ans1);

    }

    return 0;
}
