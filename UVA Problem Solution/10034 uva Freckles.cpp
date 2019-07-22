
#include <bits/stdc++.h>
#define maxi 110
using namespace std;
typedef pair<int,int>p;
vector< pair<double,p> >v;
int group[maxi];
int cas=1,n;

void initialize()
{
    for(int i=1; i<=n+1; i++)group[i]=i;
}

int root(int i)
{
    while(i != group[i]) group[i]=group[group[i]], i=group[i];
    return i;
}

bool unioon(int a, int b)
{
    int ra=root(a);
    int rb=root(b);
    //cout<<"R  "<<a<<"  "<<b<<"  "<<ra<<"  "<<rb<<endl;
    if(ra==rb) return false;
    group[ra]=group[rb];
    return true;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        initialize();
        double x[n+2],y[n+2];
        for(int i=1; i<=n; i++)  scanf("%lf %lf",&x[i],&y[i]);

        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                double t1=x[j]-x[i], t2=y[j]-y[i];
                double dis =sqrt( powl(t1,2)+powl(t2,2) );
                v.push_back(make_pair(dis,make_pair(i,j)));
            }
        }

        sort(v.begin(),v.end());
        double total=0;
       // initialize();
        for(int i=0; i<(int)v.size(); i++)
        {
            double w=v[i].first;
            int x=v[i].second.first, y=v[i].second.second;

            if(unioon(x,y)) total+=w;
        }
        printf("%.2f\n",total);
        if(t)printf("\n");
        vector< pair<double,p> >v1;
        swap(v,v1);
    }
    return 0;
}
