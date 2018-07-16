
#include <bits/stdc++.h>
#define ma 210
using namespace std;
vector< pair<double,pair<int,int> > >v;
map<string,int>mp;
int group[ma],n,sz[ma];
int  root(int i)
{
    while(i != group[i]) i=group[group[i]];
    return i;
}

bool unioon(int a, int b)
{
    int ra=root(a), rb=root(b);
    if(ra==rb) return false;
    if(sz[rb]>sz[ra]) group[ra]=group[rb], sz[rb]+=sz[ra];
    else group[rb]=group[ra], sz[ra]+=sz[rb];
 //   cout<<"A  "<<a<<"  "<<b<<endl;
    return true;
}

void initialize()
{
    for(int i=0; i<=n; i++) group[i]=i, sz[i]=1;
}

double dist(int x1, int y1, int x2, int y2)
{
    double t=sqrt( powl(x2-x1,2)+powl(y2-y1,2) );
    return t;
}
int main()
{
    int cas=1;
    while(scanf("%d",&n)==1 && n)
    {
        int x[n+1],y[n+1];

        for(int i=0; i<n; i++) cin>>x[i]>>y[i];

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double w=dist(x[i],y[i],x[j],y[j]);
                v.push_back(make_pair(w,make_pair(i,j)));
            }
        }
        sort(v.begin(),v.end());
        double maxi=0;
        initialize();
        for(int i=0; i<(int)v.size(); i++)
        {
            double w=v[i].first;
            int a=v[i].second.first, b=v[i].second.second;
            //cout<<"F  "<<a<<"    "<<b<<"   "<<w<<endl;
            if( unioon(a,b) ) maxi=max(maxi,w);
            if(root(0)==root(1)) break;
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",cas++,maxi);
        v.clear();
        mp.clear();
    }
    return 0;
}
