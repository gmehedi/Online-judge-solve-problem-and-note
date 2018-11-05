
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 10000000
using namespace std;

string s[25];
vector< pair<int,int> >pos;
int homei,homej;
bool sign[100][100];
int n,m;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

int Bfs(int i1, int j1)
{
    queue< pair<int,pair<int,int> > >q;
    q.push( make_pair(i1, make_pair(j1,0)) );

    while( !q.empty() )
    {
        int i2=q.front().first;
        int j2=q.front().second.first;
        int cnt=q.front().second.second;
        q.pop();

        if(i2 == homei && j2 == homej) return cnt;
        for(int i=0; i<4; i++)
        {
            int i3=fx[i]+i2;
            int j3=fy[i]+j2;
            if( sign[i3][j3] && i3>= 0 && i3<n && j3>=0 && j3<m )
            {
                if(s[i3][j3] != 'm' && s[i3][j3] != '#') q.push( make_pair(i3, make_pair(j3,cnt+1) ) ), sign[i3][j3]=false;
            }
        }
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        char temp[100];
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%s",temp), s[i]=(string) temp;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if( s[i][j] == 'a' || s[i][j] == 'b' || s[i][j] == 'c' ) pos.push_back(make_pair(i,j));
                if(s[i][j] == 'h') homei=i, homej=j;
            }
        }
        int len=(int)pos.size(),maxi=0;
        for(int i=0; i<len; i++)
        {
            memset(sign,true,sizeof sign);
            maxi=max( maxi,Bfs(pos[i].first,pos[i].second) );
        }
        printf("Case %d: %d\n",cas++,maxi);
        pos.clear();
    }
    return 0;
}
