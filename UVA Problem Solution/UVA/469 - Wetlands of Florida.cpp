
#include<bits/stdc++.h>
#define maxi 200
using namespace std;
string s[maxi];
bool b[maxi][maxi];
long long cnt=0;
int n,m;
void dfs(int x, int y)
{
 // cout<<"X   "<<x<<"   "<<y<<"   "<<b[x][y]<<"   "<<s[x][y]<<endl;
    if(b[x][y] || s[x][y] !='W' ) return;
    b[x][y]=true;
    cnt++;
  //  cout<<"CT  "<<cnt<<endl;
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            int a=x+i;
            int b=y+j;
            if(a>=0 && b>=0 && a<n && b<m )
            {
                dfs(a,b);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d ",&t);
    bool tt=false;
    while(t--)
    {
        n=0;
        if(tt)cout<<endl;
        tt=true;
        while(1)
        {
            string temp;
            getline(cin,temp);
            m=0;
            if(s[0][0]=='W' || s[0][0]=='L') m = (int)s[0].size();
            if(temp[0]=='\0') break;
            if(temp[0]!='L' && temp[0] != 'W')
            {
               // for(int i=0; i<n; i++)cout<<s[i]<<endl;
                stringstream is(temp);
                int i=0,j=0;
                cnt=0;
                int t;
                memset(b,false,sizeof b);
                while(is>>t)
                {;
                    if(i==0){ i=t; continue; }
                    j=t;
                }
                dfs(i-1,j-1);
                printf("%lld\n",cnt);
            }
            else
            {
                s[n++]=temp;
            }
        }
    }
    return 0;
}
