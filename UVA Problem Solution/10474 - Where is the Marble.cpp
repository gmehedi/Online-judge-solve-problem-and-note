

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,cas=1;
    while(scanf("%d %d", &n,&q)==2 )
    {
        if(n==0 && q==0) break;
        vector<int>v;
        for(int i=0; i<n; i++)
        {
            int temp;
            scanf("%d", &temp);
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        printf("CASE# %d:\n",cas++);
        for(int i=0; i<q; i++)
        {
            int temp;
            scanf("%d", &temp);
            auto t = lower_bound(v.begin(),v.end(),temp);
            int low = t-v.begin();

            if(v[low]==temp)printf("%d found at %d\n",temp,low+1);
            else printf("%d not found\n",temp);
        }
    }
    return 0;
}
