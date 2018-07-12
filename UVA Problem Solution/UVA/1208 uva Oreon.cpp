
#include <bits/stdc++.h>
#define maxi 60010
using namespace std;
typedef pair<int,int>p;
vector< pair<int,p> >v;
vector< pair<int,p> >res;
int group[maxi],sz[maxi];
int cas=1,n;

void initialize()
{
    for(int i=0; i<=n; i++)group[i]=i,sz[i]=1;
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

bool check()
{
    int t=root(0);
    for(int i=1; i<n; i++)
    {
        if(root(i) != t) return false;
    }
    return true;
}

void print()
{
    printf("Case %d:\n",cas++);
    for(int i=0; i<res.size(); i++)
    {
        int x=res[i].second.first, y=res[i].second.second, w=res[i].first;
        printf("%c-%c %d\n",x+'A',y+'A',w);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; i++)
        {
            string s;
            getline(cin,s);
            int temp=0,cnt=0;
            for(int j=0; j<(int)s.size(); j++)
            {
                if(s[j]>='0' && s[j]<='9') temp=temp*10+(s[j]-'0');
                if(s[j]==',')cnt++;
                if( (s[j+1]==',' || s[j+1]=='\0') && temp !=0)
                    v.push_back(make_pair(temp,make_pair(i,cnt))), temp=0;
            }

        }
        initialize();
       // for(int i=0; i<n; i++)cout<<"G "<<root(i)<<endl;
        sort(v.begin(),v.end());
        for(int i=0; i<(int)v.size(); i++)
        {
            int x=v[i].second.first, y=v[i].second.second, w=v[i].first;

            if( unioon(x,y) )
            {
                res.push_back(make_pair(w,make_pair(x,y)));
            }
        }
        sort(res.begin(),res.end());
        print();
        vector< pair<int,p> >v1;
        vector< pair<int,p> >res1;
        swap(v,v1);
        swap(res,res1);
    }
    return 0;
}
