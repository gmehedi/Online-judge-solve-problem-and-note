#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxl 10000000
using namespace std;

string s[510];
int n,m,q;
bool sign[505][505];
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int dp[505][505];
vector<pair<int,int> >grouf;

void Dp(int cnt)
{
    int len= (int) grouf.size();
    for(int i=0; i<len; i++)
    {
        int it=grouf[i].first;
        int jt=grouf[i].second;
        dp[it][jt]=cnt;
    }
    grouf.clear();
}
int Bfs(int i1, int j1)
{
    int cnt=0;
    queue< pair<int,int > >q;
    q.push( make_pair(i1,j1) );
    sign[i1][j1]=false;
    while( !q.empty() )
    {
        int i2=q.front().first;
        int j2=q.front().second;
        grouf.push_back(make_pair(i2,j2)); // Travarsal node store because all of has same cristal
        q.pop();

        if(s[i2][j2] == 'C' || s[i2][j2] == 'c') cnt++;//cout<<"T  "<<s[i2][j2]<<"  "<<i2<<"  "<<j2<<endl;

        for(int i=0; i<4; i++)
        {
            int i3=fx[i]+i2;
            int j3=fy[i]+j2;

            if( sign[i3][j3] && i3>= 0 && i3<n && j3>=0 && j3<m )
            {
                if( s[i3][j3] != '#' ) q.push( make_pair(i3,j3) ), sign[i3][j3]=false;
            }
        }
    }
    return cnt;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);

    while(t--)
    {
        char temp[1000];
        memset(dp,0,sizeof dp);
        memset(sign,true,sizeof sign);

        scanf("%d %d %d",&n,&m,&q);
        for(int i=0; i<n; i++) scanf("%s",temp), s[i]=(string) temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) if( sign[i][j] && s[i][j] != '#' ) Dp( Bfs(i,j) );
        }

        printf("Case %d:\n",cas++);
        while(q--)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            printf("%d\n",dp[i-1][j-1]);
        }
        string temps[510];
        swap(temps,s);
    }
    return 0;
}

