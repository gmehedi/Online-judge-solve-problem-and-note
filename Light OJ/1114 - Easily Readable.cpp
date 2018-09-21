
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
# define ll  long long
using namespace std;

char s[100000],temp[100000];
int main()
{
    int t,cas=1,len=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map<string,int>mp;
        for(int i=0; i<n; i++)
        {
             scanf("%s",s);
             len=(int)strlen(s);
             if(len>2) sort(s+1,s+len-1);
             mp[s]++;
        }

        int q;
        scanf("%d",&q);
        getchar();
        printf("Case %d:\n",cas++);
        for(int i=0; i<q; i++)
        {
            int ans=1;
            gets(temp);
            istringstream t(temp);

            while( t >> s )
            {
                len=strlen(s);
                //cout<<"T  "<<temp<<endl;
                if(len>2) sort(s+1,s+len-1);

                ans *= mp[s];
                if(ans==0) break;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}
