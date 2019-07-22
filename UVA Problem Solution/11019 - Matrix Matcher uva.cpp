#include<bits/stdc++.h>
#define p1 31
#define p2 51
#define maxl 1110
#define maxp 1110

using namespace std;
long long mod=1e9+7;

long long power1[maxp+2],power2[maxp+2],result[maxl+2][maxl+2],result1[maxl+2][maxl+2];
int n,m,x,y;
string text[maxl+2], pattern[maxl+2];

void Power_generate()
{
    power1[0]=1,power2[0]=1;

    for(int i=1; i<=maxp; i++) power1[i]= (power1[i-1]*p1)%mod, power2[i]=(power2[i-1]*p2)%mod;
}

long long Pattern_hashing()
{
    vector<long long>v;
    for(int i=0; i<x; i++)
    {
        long long temp=0;
        for(int j=0; j<y; j++)
        {
            temp= ( temp+( (int)pattern[i][j]*power1[j] ) )%mod;
        }
        v.push_back(temp);
    }

    long long total=0;
    for(int i=0; i<(int)v.size(); i++)
    {
        total=(total+(v[i]*power2[i])) %mod;
    }

    total=(total*power1[maxp])%mod;
    total=(total*power2[maxp])%mod;
    //cout<<"patt      "<<total<<endl;
    return total;
}

long long Value(int r1, int c1, int r2, int c2)
{
    long long total=result[r2][c2];
   // cout<<"Textp  "<<total<<" "<<r1<<"  "<<c1<<"  "<<r2<<"  "<<c2<<endl;
    if(r1>0 && c1>0)
    {
        total=( (total+result[r1-1][c1-1])+mod )%mod;
    }

    if(r1>0)
    {
        total=( (total-result[r1-1][c2])+mod )%mod;
    }
    if(c1>0)
    {
        total=( (total-result[r2][c1-1])+mod )%mod;
    }

    int eqp2= maxp-r1, eqp1=maxp-c1;
   // cout<<"P  "<<eqp1<< "  "<<eqp2<<"  "<<maxp<<"  "<<eqp1+r1<<" "<<eqp2+c1<<endl;
    total= (total*power1[eqp1]) %mod;
    total= (total*power2[eqp2]) %mod;
   // cout<<"TXTO    "<<total<<endl;
    return total;
}

void Text_hashing()
{
    for(int i=0; i<n; i++)
    {
        long long temp=0;
        for(int j=0; j<m; j++)
        {
            temp= ( temp+( (int)text[i][j]*power1[j] ) )%mod;
            result[i][j]=temp;
        }
    }
//cout<<"ttR1  "<<result[0][0]<<endl;
    for(int j=0; j<m; j++)
    {
        long long temp=0;
        for(int i=0; i<n; i++)
        {
            temp=( temp+(result[i][j]*power2[i]) )%mod;
            result[i][j]=temp;
        }
    }
    //cout<<"RRR   "<<result[0][0]<<endl;
    for(int i=0; i<n-x+1; i++)
    {
        for(int j=0; j<m-y+1; j++)
        {
            int r1=i,c1=j,r2=i+x-1,c2=j+y-1;
            result1[r1][c1]= Value(r1,c1,r2,c2);
        }
    }

}
int main()
{
    int t;
    Power_generate();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        cin.ignore();
        for(int i=0; i<n; i++) cin>>text[i];
       // cout<<text[0]<<endl;
        scanf("%d %d",&x,&y);
        cin.ignore();
        for(int i=0; i<x; i++) cin>>pattern[i];
     //   cout<<pattern[0]<<endl;

        long long total_hash=Pattern_hashing();

      //  cout<<"T  "<<total_hash<<endl;
        Text_hashing();

        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
               // cout<<"R  "<<result[i][j]<<endl;
                if(total_hash == result1[i][j]) ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
