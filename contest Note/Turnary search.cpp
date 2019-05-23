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