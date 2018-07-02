
#include<bits/stdc++.h>
#define mx 10000
using namespace std;
int node,edge;
vector<int>v[mx];
bool b[mx];

queue<int>q;
void BFS()
{
    for(int i=1; i<=node; i++)
    {
        q.push(i);
        b[i]=true;
        while( ! q.empty() )
        {
             int f=q.front();
             q.pop();
             for(int j=0; j<=v[f].size(); j++)
             {
                 if(!b[j])
                 {
                     q.push(j);
                     b[j]=true;
                 }
             }
        }

    }
}
int main()
{

    scanf("%d%d",&node,&edge);
    memset(b,false,sizeof b);
    for(int i=1; i<=edge; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }
    printf("''-------The Graph is--------''\n\n");

    for(int i=1; i<=node; i++)
    {
        printf("%d-----> ",i);
        for(int j=0; j<v[i].size(); j++)
        {
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }

 BFS();

    return 0;
}
