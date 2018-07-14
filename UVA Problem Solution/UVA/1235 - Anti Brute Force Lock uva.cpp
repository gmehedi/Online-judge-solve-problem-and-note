
#include<bits/stdc++.h>
#define N 510
using namespace std;
int n;
vector<pair<int,pair<int,int> > >v;
int group[N];

void initialize()
{
    for(int i=0; i<=n+2; i++)group[i]=i;
}

int root(int i)
{
    while(i != group[i]) i=group[ group[i] ];
    return i;
}

bool unioon(int a, int b)
 {
     int ra=root(a), rb=root(b);
     if(ra==rb) return false;
     group[ra]=group[rb];
     return true;
 }
int dist(string s1,string s2)
{
    int total=0;
    for(int i=0; i<4; i++)
    {
        int t1=s1[i]-48, t2=s2[i]-48;
        int x=abs(t1-t2);
        int  z=(10-t2)+t1;
        int y=10-x;
        total+= min(x,y);
    }
    return total;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        string s[n+2];
        int mini=INT_MAX;
        for(int i=1; i<=n; i++)
        {
            cin>>s[i];
            mini=min(mini,dist("0000",s[i]));
        }
     //   for(int i=0; i<=n; i++)cout<<"S  "<<s[i]<<endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                int w=dist(s[i],s[j]);
                v.push_back(make_pair(w,make_pair(i,j)));
            }
        }
        sort(v.begin(),v.end());
        long long total=0;
        initialize();
        for(int i=0; i<(int)v.size(); i++)
        {
            int w=v[i].first;
            int x=v[i].second.first;
            int y=v[i].second.second;
            if( unioon(x,y) ) total+=w;
        }
        printf("%lld\n",total+mini);
        v.clear();
    }
    return 0;
}
