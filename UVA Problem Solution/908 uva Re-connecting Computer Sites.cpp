
#include <bits/stdc++.h>
#define maxi 1000001
using namespace std;
typedef pair<int,int>p;
vector< pair<int,p> >v;
int group[maxi];

void initialize(int n)
{
    for(int i=0; i<=n; i++)group[i]=i;
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
    if(ra==rb) return false;
    group[ra]=group[rb];
    return true;
}
int main()
{
    int n;
    bool b=false;
    while( scanf("%d",&n) != EOF )
    {
        long long prev=0;
        int t1,t2,t3;
        initialize(n);
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            prev+=t3;
        }
        int t;
        scanf("%d",&t);
        for(int i=0; i<t; i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            v.push_back( make_pair(t3,make_pair(t1,t2)) );
        }
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&t1,&t2,&t3);
            v.push_back( make_pair(t3,make_pair(t1,t2)) );
        }
        sort(v.begin(),v.end());
        long long newcost=0;
        for(int i=0; i<(int)v.size(); i++)
        {
            t1=v[i].second.first;
            t2=v[i].second.second;
            t3=v[i].first;
            if(unioon(t1,t2))
            {
                newcost+=t3;
            }
        }
        if(b)printf("\n");
        printf("%lld\n%lld\n",prev,newcost);

        b=true;
        vector< pair<int,p> >v1;
        swap(v1,v);
    }

    return 0;
}
