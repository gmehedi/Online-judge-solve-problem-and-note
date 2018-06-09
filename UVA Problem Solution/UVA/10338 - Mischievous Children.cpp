#include<bits/stdc++.h>
using namespace std;
long long Big(int x)
{
    if(x==1 || x==0)return 1;
    return x*Big(x-1);
}
int main()
{
    string s;
    int t;
    scanf("%d ",&t);
    int cas=1;
    while( t-- )
    {
        getline(cin,s);
        int rep[30];
        memset(rep,0,sizeof rep);
        int len=(int) s.size();
        long long t1=0;

        for(int i=0; i<len; i++)
        {
               rep[s[i]-'A']++;
        }

        t1 = Big(len);
     //   cout<<"G  "<<t1<<endl;
        for(int i=0; i<30; i++)
        {
            if(rep[i]>1)
            {
               // cout<<"F     "<<rep[s[i]-'A']<<endl;
                t1=t1/Big(rep[i]);
            }
        }

         printf("Data set %d: %lld\n",cas++,t1);

    }

    return 0;
}
