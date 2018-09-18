
#include<bits/stdc++.h>
#define p1 31
#define p2 51
#define maxl 1000009
#define maxp 1000009

using namespace std;
char s[maxl+2],revs[maxl+2];
long long mod=1e9+7;

long long power[maxp+2], cum[maxp+1];
int n,m,x,y;
string text[maxl+2], pattern[maxl+2];

void Power_generate()
{
    power[0]=1;
    cum[0]=1;
    for(int i=1; i<=maxp; i++) power[i]= (power[i-1]*p1) %mod, cum[i]= (cum[i-1]%mod+power[i]%mod) %mod; //cout<<cum[i]<<endl;
}

int main()
{
    int t,cas=1;
    Power_generate();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);

        int len= strlen(s);
        strcpy(revs,s);

        int j=len-1;
        for(int i=0; i< (len/2); i++,j--) swap(revs[i],revs[j]);

        long long s_hash=0, revs_hash=0;
        for(int i=0; i<len; i++)
        {//cout<<"TTT    "<<(int)s[i]<<"  "<<power[i]<<endl;
            s_hash = ( s_hash%mod+( (s[i]*power[i] )%mod ) ) %mod;
            revs_hash = ( revs_hash%mod+(revs[i]*power[i])%mod ) %mod;
        }
      //  cout<<"T "<<s_hash<<"  "<<revs_hash<<endl;
        int q;
        scanf("%d",&q);
        cin.ignore();
        printf("Case %d:\n",cas++);
      //  cout<<"R  "<<revs_hash<<"  "<<s_hash<<endl;
        while(q--)
        {
            char pos,elem;
            int k;
            cin>>pos>>elem>>k;
            long long element=(int)elem;
            if(pos=='L')
            {
                s_hash=( ((element*cum[k-1])%mod) + ( (s_hash*power[k] )%mod) ) %mod;
                revs_hash= ( revs_hash%mod+( (element*( (cum[len+k-1]-cum[len-1] )+mod )%mod)%mod ) ) %mod;
                len+=k;
                //cout<<"CC  "<<cum[k-1]<<"  "<<cum[len+k-1]<<"  "<<cum[len-1]<<endl;
            }
            else
            {
                revs_hash=( ((element*cum[k-1])%mod)+(revs_hash%mod*power[k]) %mod ) %mod;
                s_hash= ( s_hash%mod+(element*( (cum[len+k-1]-cum[len-1] )+mod )%mod ) ) %mod;
                len+=k;
                 //cout<<"RR  "<<cum[k-1]<<"  "<<cum[len+k-1]<<"  "<<cum[len-1]<<endl;
            }

          //  cout<<"R  "<<revs_hash<<"  "<<s_hash<<endl;

             if(revs_hash == s_hash) printf("Yes\n");
             else printf("No\n");
        }
    }

    return 0;
}
