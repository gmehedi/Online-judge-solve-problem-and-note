
#include<bits/stdc++.h>
using namespace std;
struct jar
{
    int l,h,w,d;
};
struct jar j;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<jar>v;
        for(int i=0; i<n; i++)
        scanf("%d%d%d%d",&j.l,&j.h,&j.w,&j.d),v.push_back(j);
        int V;
        scanf("%d",&V);
        double volume=0.0;
        for(int i=0; i<n; i++)volume+=v[i].h*v[i].w*v[i].d;
        if(volume<V)
        {
            printf("OVERFLOW\n");
            continue;
        }

        double low=0.0,high=1e8,presentlayer=0.0;
        while(abs(high-low)>0.0000001)
        {
            volume=0.0;
            presentlayer=(high+low)/2;
            for(int i=0; i<n; i++)
            {
                 if(presentlayer<=v[i].l) continue;
                 else if( (presentlayer>v[i].l) && v[i].h+v[i].l<=presentlayer) volume+=(v[i].h*v[i].w*v[i].d);
                 else volume+=( (presentlayer-v[i].l)*v[i].w*v[i].d);
            }
          // cout<<"V  "<<volume<<"  "<<V<<endl;
            if(volume>=V)high=presentlayer;
            else low=presentlayer;
        }
        printf("%.2f\n",presentlayer);
    }
    return 0;
}
