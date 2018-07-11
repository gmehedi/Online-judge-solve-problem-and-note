
#include <bits/stdc++.h>
#define maxi 150
using namespace std;
typedef pair<int,int>p;
vector< pair<int,p> >v;
int group[maxi];
int cas=1;

void initialize(int n)
{
    for(int i=0; i<=n+1; i++)group[i]=i;
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int t1,t2,t3;
        initialize(n);
        while(scanf("%d%d%d",&t1,&t2,&t3)==3)
        {
            if(t1==0 && t2==0 && t3==0)break;
            v.push_back( make_pair(t3,make_pair(t1,t2)) );
        }
        sort(v.begin(),v.end());
        long long lowest=0;
        for(int i=0; i<(int)v.size(); i++)
        {
            int x1=v[i].second.first, x2=v[i].second.second, x3=v[i].first;
            if( unioon(x1,x2) )
            {
                lowest+=x3;
            }
        }
        initialize(n);
        long long biggest=0;
        for(int i=(int)v.size()-1; i>=0; i--)
        {
            int x1=v[i].second.first, x2=v[i].second.second, x3=v[i].first;
            if( unioon(x1,x2) )
            {
                biggest+=x3;
            }
        }

        if( (lowest+biggest)%2==0)printf("Case %d: %lld\n",cas++,(lowest+biggest)/2);
        else printf("Case %d: %lld/2\n",cas++,lowest+biggest);
        vector< pair<int,p> >v1;
        swap(v,v1);
    }
    return 0;
}
