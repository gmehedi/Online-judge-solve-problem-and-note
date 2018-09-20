// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define p1 31
#define maxl 30100
#define maxp 30100
#define ull unsigned long long
using namespace std;
ull power[maxp];
void Power_generate()
{
    power[0]=1;
    for(int i=1; i<maxp; i++) power[i]=power[i-1]*p1;
}
char s[maxl],revs[maxl];
ull hashv[maxl],rhashv[maxl];
int len=0;

void Hashing()
{
    strcpy(revs,s);
    int j=len-1;
    for(int i=0; i<len/2; i++,j--) swap(revs[i],revs[j]);

    hashv[0]=0, rhashv[0]=0;
    for(int i=0; i<len; i++) hashv[i+1]= (hashv[i]+(ull)(power[i]*(int)s[i]));
    for(int i=0; i<len; i++) rhashv[i+1]= (rhashv[i]+(ull)(power[i]*(int)revs[i]));

}

ull get1(int l, int r)
{
    int eqp=maxp-l;
  //  cout<<"g1  "<<hashv[r]<<"  "<<hashv[l-1]<<endl;
    return (hashv[r]-hashv[l-1])*power[eqp];

}
ull get2(int l, int r)
{
     int eqp=maxp-l;
    // cout<<"g2  "<<rhashv[r]<<"  "<<rhashv[l-1]<<"   "<<rhashv[4]<<endl;
    return (rhashv[r]-rhashv[l-1])*power[eqp];
}
int main()
{
    int k;
    Power_generate();
    scanf("%d",&k);
    scanf("%s",s);
    len=strlen(s);
    Hashing();
    ull ans=0;
    for(int i=1; i<=len-k+1; i++)
    {
        int l1=i,r1=i+k-1, l2=len-(i+k-1)+1,r2=len-i+1;
      // cout<<"L  "<<l1<<"  "<<r1<<"  "<<l2<<" "<<r2<<endl;
        ull t1=get1(l1,r1 ), t2= get2(l2,r2);
     //   cout<<"T  "<<t1<<" "<<t2<<endl;
        if(t1==t2) ans++;
    }
    printf("%lld",ans);
}
