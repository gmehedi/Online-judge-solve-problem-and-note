
#include<bits/stdc++.h>
#define N 100010
using namespace std;

int sz[N],root[N];
vector< pair< int,pair< int,int > > >v;

void initialize()
{
    v.clear();
    for(int i=0; i<N; i++) sz[i]=1, root[i]=i;
}

int find_root(int i)
{
    while(i != root[i]) i=root[ root[ root[i] ] ];
    return i;
}

bool unioon(int x,int y)
{
    int rx=find_root(x), ry=find_root(y);
    if(rx != ry)
    {
        if(sz[rx] > sz[ry]) sz[rx]+=sz[ry], root[ry]=root[rx];
        else sz[ry]+=sz[rx], root[ry]=root[rx];
        return true;
    }
    return false;
}

int distance(int x1, int y1, int x2, int y2)
{
    return ceil( sqrt( powl(x2-x1,2)+powl(y2-y1,2) ) );
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int>x,y;
        int x1,y1;
        initialize();
        while(scanf("%d",&x1)==1 && x1 != -1)
        {
            scanf("%d",&y1);
            x.push_back(x1), y.push_back(y1);
        }

        for(int i=0; i<(int)x.size()-1; i++)
        {
            for(int j=i+1; j<(int)x.size(); j++)
            {
                int dis=distance(x[i],y[i],x[j],y[j]);
                v.push_back( make_pair( dis,make_pair(i+1,j+1) ) );
                v.push_back( make_pair( dis,make_pair(j+1,i+1) ) );
            }
        }

        sort(v.begin(),v.end());
        for(int i=0; i<(int)v.size(); i++)
        {
            int w=v[i].first, u=v[i].second.first, v1=v[i].second.second;
           // cout<<"W  "<<w<<"  "<<u<<"  "<<v1<<endl;
            if( unioon(u,v1))
            {
                n++;
                if(n>=(int)x.size())
                {
                    printf("%d\n",w);
                    break;
                }
            }
        }


    }
}
