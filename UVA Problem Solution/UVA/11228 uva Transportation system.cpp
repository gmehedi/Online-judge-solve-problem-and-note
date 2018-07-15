
#include <bits/stdc++.h>
#define maxi 1010
using namespace std;
vector< pair<double,pair<int,int> > >same;
vector< pair<double,pair<int,int> > >diff;
int group[maxi],n,m,cas=1;

int  root(int i)
{
    while(i != group[i]) i=group[group[i]];
    return i;
}

double value(int x1,int y1, int x2, int y2)
{
    return sqrt( powl(x2-x1,2)+powl(y2-y1,2) );
}

bool unioon(int a, int b)
{
    int ra=root(a), rb=root(b);
    if(ra==rb) return false;
    group[ra]=group[rb];
 //   cout<<"A  "<<a<<"  "<<b<<endl;
    return true;
}

void initialize()
{
    for(int i=0; i<=n; i++)group[i]=i;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int x[n+2],y[n+2],state=0;
        for(int  i=0; i<n; i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double w=value(x[i],y[i],x[j],y[j]);
                if(w<=m)
                {
                    same.push_back(make_pair(w,make_pair(i,j)));
                }
                else
                {
                    diff.push_back(make_pair(w,make_pair(i,j)));
                }
            }
        }

        sort(same.begin(),same.end());
        sort(diff.begin(),diff.end());
        double samet=0,difft=0;

        initialize();

        for(int i=0; i<(int)same.size(); i++)
        {
            int x=same[i].second.first, y=same[i].second.second;
            double w=same[i].first;
            //cout<<"W  "<<w<<"  "<<samet<<endl;
            if(unioon(x,y)) samet+=w;
        }

       state=0;
        for(int i=0; i<(int)diff.size(); i++)
        {
            int x=diff[i].second.first, y=diff[i].second.second;
            double w=diff[i].first;
            if(unioon(x,y)) difft+=w,state++;// cout<<"X  "<<x<<"  "<<y<<"  "<<w<<endl;
        }
        printf("Case #%d: %d %.0f %.0f\n",cas++,state+1,samet,difft);
        same.clear();
        diff.clear();

    }
    return 0;
}
