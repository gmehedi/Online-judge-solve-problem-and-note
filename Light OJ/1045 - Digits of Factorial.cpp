
#include<bits/stdc++.h>
using namespace std;
vector<double>v;
void store()
{
    double sum=0;
    for(int i=1; i<=1000001; i++)
    {
        sum+= log10(i);
        v.push_back(sum);
    }
}
int main()
{
    int t,cas=1;
    store();
    scanf("%d",&t);
    while(t--)
    {
        int n,b;
        scanf("%d %d",&n,&b);
        double t= ( log(10)*v[n-1] )/log(b);
        long long digit=(long long)t;
        printf("Case %d: %lld\n",cas++,digit+1);
    }

    return 0;
}
