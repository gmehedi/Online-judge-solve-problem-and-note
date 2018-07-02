
#include <bits/stdc++.h>
#define maxi 1000000
using namespace std;
vector<int>graph[maxi];
bitset<maxi>sign;
void creat(char x, char y)
{
    int a=x-'A',b=y-'A';
    graph[a].push_back(b);
    graph[b].push_back(a);
}
int len,cnt=0;
void bfs2(int u)
{
   // cout<<"U  "<<u<<endl;
    queue<int>q;
    q.push(u);
    while( !q.empty() )
    {
        int f=q.front();
        q.pop();
        sign[f]=true;
        for(int i=0; i<(int) graph[f].size(); i++)
        {
            int k=graph[f][i];
            if(!sign[k]) q.push(k), sign[k]=true;
        }
    }
}
void bfs1()
{
    for(int i=0; i<=len; i++)
    {
        if(!sign[i])bfs2(i),cnt++;
    }
}
int main()
{
    int n;
    bool b=false;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        if(b)cout<<endl;
        else b=true;
        char ch;
        sign.reset();
        cnt=0;
        cin>>ch;
        cin.ignore();

        len=ch-'A';
        while(1)
        {
            string s;
            getline(cin,s);
            if(s=="")break;
            creat(s[0],s[1]);
        }
     //   cout<<"gfd"<<endl;
        bfs1();
        cout<<cnt<<endl;
        for(int i=0; i<=len; i++) graph[i].clear();
    }

    return 0;
}
