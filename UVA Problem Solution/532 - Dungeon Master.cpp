
#include <bits/stdc++.h>
#define maxi 2000
using namespace std;
int n,r,c,f1,f2,f3,l1,l2,l3=0;
int cordinate[6][6]={ {-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1} };

bool b[100][100][100];
string s[maxi][maxi];
struct node
{
    int I;
    int J;
    int K;
    int cost;
};

bool check(int t1, int t2, int t3)
{
    if(t1>=0 && t2>=0 && t3>=0 && t1<n && t2<r && t3<c && s[t1][t2][t3] !='#' && b[t1][t2][t3] ) return true;
    else return false;
}
int Bfs()
{
    //cout<<"L  "<<f1<<"  "<<f2<<" "<<f3<<"  L "<<l1<<"   "<<l2<<"  "<<l3<<endl;
    queue<node>q;
    q.push({f1,f2,f3,0});
    b[f1][f2][f3]=false;
    while( !q.empty() )
    {
        struct node temp;
        temp=q.front();
        int x=temp.I;
        int y=temp.J;
        int z=temp.K;
        int w=temp.cost;
        q.pop();
        if(x==l1 && y==l2 && z==l3 ){ printf("Escaped in %d minute(s).\n",w);  return 0; }

        for(int i=0; i<6; i++)
        {
            int t1=x+cordinate[i][0];
            int t2=y+cordinate[i][1];
            int t3=z+cordinate[i][2];
            if( check(t1,t2,t3) )
            {
                q.push({t1,t2,t3,w+1});
                b[t1][t2][t3]=false;
            }
        }

    }
    printf("Trapped!\n");
}
int main()
{

    while( scanf("%d%d%d",&n,&r,&c)==3 )
    {
       if(n==0 && r==0 && c==0) return 0;
        memset(b,true,sizeof b);
        f1=0,f2=0,f3=0,l1=0,l2=0,l3=0;

        for(int i=0; i<n; i++)
        {
             getchar();
            for(int j=0; j<r; j++)
            {
                getline(cin,s[i][j]);
                for(int k=0; k<c; k++)
                {
                    if(s[i][j][k]=='S') f1=i,f2=j,f3=k;
                    if(s[i][j][k]=='E') l1=i,l2=j,l3=k;
                }
            }

        }
        Bfs();
        for(int i=0; i<n; i++)
            for(int j=0; j<r; j++) s[i][j].clear();
    }

    return 0;
}
