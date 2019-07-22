
#include<bits/stdc++.h>
using namespace std;
int n,m;
int res[10000][10000];
int Lcs( char *s1, char *s2)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if( i==0 || j==0 )
            {
                res[i][j]=0;
            }
            else
            {
                if(s1[i-1]==s2[j-1])
                {
                    res[i][j] = res[i-1][j-1]+1;
                  //  cout<<"V  "<<res[i-1][j-1]<<endl;
                }
                else
                {
                    if(res[i-1][j]>res[i][j-1])res[i][j]=res[i-1][j];
                    else res[i][j]=res[i][j-1];
                }
            }
        }
    }
    int index=res[n][m];
  //  cout<<"I  "<<index<<endl;
    char s[index+1];
    s[index]='\0';
    int i=n,j=m;
    while(i>0 && j>0)
    {
       // cout<<"I  "<<i<<"  J   "<<j<<"       "<<s1[i]<<"   "<<s2[j]<<endl;
        if(s1[i-1]==s2[j-1])
        {

            index--;
       //     cout<<"IN     "<<index<<"          "<<s1[i]<<endl;
            s[index] = s1[i-1];
            i--;
            j--;
        }

        else if(res[i-1][j]>res[i][j-1])
        {
            i--;
        }
        else j--;
    }

    printf("%s\n",s);

}

int main()
{
    char s1[10000],s2[10000];
    while(gets(s1))
    {
        gets(s2);
        n=strlen(s1);
        m=strlen(s2);
        sort(s1,s1+n);
        sort(s2,s2+m);

        Lcs(s1,s2);
    }
    return 0;
}
