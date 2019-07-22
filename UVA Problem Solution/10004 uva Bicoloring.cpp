

#include<bits/stdc++.h>
#define mx 210
using namespace std;
vector<int>v[mx];
char c[mx];
queue<int>q;
vector<bool>b;
vector<char>sign;
int n,l;
bool Bfs()
{

    for(int i=0; i<n; i++)
    {
        if(b[i])
        {
            q.push(i);
            b[i]=false;
            while( !q.empty() )
            {
                int f=q.front();
                q.pop();
             //   cout <<"F  "<<f<<endl;
                if(sign[f]=='c')
                {
                    sign[f]='B';
                }
                for(auto j=v[f].begin(); j != v[f].end(); j++)
                {
                    if(b[*j])
                    {
                        q.push(*j);
                        b[*j]=false;
                        if(sign[f]=='B')sign[*j]='W';
                        else sign[*j]='B';

                    }
                    if(sign[*j]==sign[f])
                    {
                        //cout <<"N  "<<sign[*j]<<"   "<<sign[f]<<endl;
                            return false;
                    }
                }

                }

            }

    }

       return true;
}


void Push()
{
    int x,y;
    scanf("%d%d",&x,&y);
    v[x].push_back(y);
    v[y].push_back(x);
}
int main()
{
//    memset(b,true,sizeof b);


    while(scanf("%d",&n)==1 && n != 0)
    {
        b.assign(mx,true);
        sign.assign(mx,'c');
        scanf("%d",&l);
        for(int i=0; i<l; i++)
        {
            Push();
        }
    /* printf("The graph is\n\n");
        for(int i=0 ;i<n; i++)
        {
            printf("%d -->   ",i);
            for(int j=0 ;j<v[i].size(); j++)
            {
                printf("%d ",v[i][j]);
            }
            printf("\n");
        }*/

         if(!Bfs() )printf("NOT BICOLORABLE.\n");
         else printf("BICOLORABLE.\n");

         for(int i=0; i<n; i++)
         {
             v[i].clear();
         }
         while(!q.empty())q.pop();
         sign.clear();
         b.clear();

    }

    return 0;
}
