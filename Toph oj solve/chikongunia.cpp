
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#include<unordered_map>
#define maxl 1001000
#define maxp 1001000
# define ull unsigned long long
#define p1 31
#define p2 51
using namespace std;

ull power[maxp+2];
ull mod1 = 1e9+9;

void Power_generate()
{
    power[0]=1;
    for(ull i=1; i<=maxp; i++)
    {
        power[i]= ((power[i-1])*p1 );
     //   cout<<"G  "<<((power[i-1])*p1 )<<endl;
        //cout<<"I  "<<i<<"  "<<power[i]<<endl;
    }
}
long long ans=0;
unordered_map<ull,ull>mp;

ull Hashing( string &s, int &len)
{
    ull hashv=0;
    for(int i=0; i<len; i++) hashv= hashv+( (int)s[i]*power[i] );

    for(int i=0; i<len; i++)
    {
        for(char j='a'; j<='z'; j++)
        {
            if(s[i] != j)
            {
               // cout<<"j "<<j<<endl;
                ull hashv2= (hashv-((int)s[i]*power[i]) + ((int)j*power[i]) );
                if( mp.find(hashv2) != mp.end() ) ans+=mp[hashv2];
            }
        }
    }
    mp[hashv]++;
   // cout<<"M  "<<mp.size()<<endl;
}
int n,len;
int main()
{
   // ios_base::sync_with_stdio(false);
   time_t start= clock();
    Power_generate();
    scanf("%d %d",&n,&len);
    cin.ignore();
    ans=0;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        Hashing(s,len);
    }
   // cout<<"G"<<endl;
    printf("%lld",ans);
  //  cout<<"T  "<<endd-start<<endl;
    //cout<<"T "<<endl;
    return 0;
}
