
#include<bits/stdc++.h>
using namespace std;
int n,t;
int hight[10010],cost[10010];
double Total_cost(double value)
{
    double ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=fabs(value-hight[i])*cost[i];
    }
    return ans;
}

long long Turnary(double left, double right)
{
    double mid1=0,mid2=0;
    while( abs(right-left)>0.0001 )
    {
        mid1=left+(right-left)/3, mid2=mid1+(right-left)/3;
        if(Total_cost(mid1)>Total_cost(mid2)) left=mid1;
        else right=mid2;
    }
    return min(Total_cost(floor(mid2)),Total_cost(ceil(mid2)));
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&hight[i]);
        for(int i=0; i<n; i++) scanf("%d",&cost[i]);
        printf("%lld\n",Turnary(0.0,10100.00));
    }
    return 0;
}
