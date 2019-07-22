#include<cstdio>
int main()
{
    int n,k,d,m,total;
    while(scanf("%d %d",&n,&k)==2)
    {
        int n1=n;
        total=0;
        while(n1>=k)
        {
            d=n1/k;
            total+=d;
            m=n1%k;
            n1=d+m;

        }
        printf("%d\n",(n+total));
    }
    return 0;
}
