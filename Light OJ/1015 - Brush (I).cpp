
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
       // printf("\n");
        scanf("%d",&n);
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp>=0) sum+=temp;
        }
        printf("Case %d: %lld\n",cas++,sum);
    }
    return 0;
}
