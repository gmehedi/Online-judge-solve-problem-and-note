
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
int n;

bool Check2(string toy, string ch[4])
{
    for(int i=0; i<3; i++)
    {
        bool sign=false;
        for(int  j=0; j<(int)ch[i].size(); j++)
        {
            if(toy[i] == ch[i][j]) { sign=true; break; }
        }
        if( !sign ) return true;
    }
    return false;
}

bool Check(string toy,string con[102][4])
{
    if(n == 0) return true;

    for(int i=0; i<n; i++)
    {
       if( !Check2(toy,con[i]) ) return false;
    }
    return true;
}

int mod =(int) ('z'-'a')+1;

string up(string temp, int &i)
{
    int val= temp[i]-'a';
    val=(val+1)%mod;
    temp[i]=val+'a';
    return temp;
}

string low(string temp, int i)
{
    int val= temp[i]-'a';
    val=(val-1);
    if(val<0) val='z'-'a';
    temp[i]=val+'a';
    return temp;
}

ll bfs(string start, string dest, string con[102][4])
{
    map<string,int>mp;

    queue <pair<string, ll> >q;
    q.push( make_pair(start,0) );

    while( !q.empty() )
    {
        string temp=q.front().first;
        int cost=q.front().second;
        q.pop();

        if(temp == dest) return cost;
        for(int i=0; i<3; i++)
        {
            string temp1=up(temp,i);
            string temp2=low(temp,i);

            if( mp[temp1] == 0 && Check(temp1,con) )
            {
                q.push( make_pair(temp1,cost+1) );
               // cout<<"T!  "<<temp1<<endl;
                mp[temp1]=1;
            }
            if( mp[temp2] == 0 && Check(temp1,con) )
            {
                q.push( make_pair(temp2,cost+1) );
              //  cout<<"T2  "<<temp2<<endl;
                mp[temp2]=1;
            }
        }
    }

    return -1;
}
int main()
{
    int t,cas=1;
    char temp[200000];

    scanf("%d",&t);

    while(t--)
    {
        char start[200000],last[200000];
        string con[100][4];

        scanf("%s %s",start,last);
        scanf("%d",&n);
        getchar();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<3; j++) scanf("%s",temp), con[i][j]=(string) temp;
        }

        if( start == last) printf("Case %d: 0\n",cas++);
        else if( !Check(start,con) || !Check(last,con) ) printf("Case %d: -1\n",cas++);
        else printf("Case %d: %lld\n",cas++,bfs(start,last,con) );
        
    }

    return 0;
}
