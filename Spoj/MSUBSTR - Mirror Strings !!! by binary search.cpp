
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
#define p1 31
#define maxl 3100
#define maxp 3100
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
int ans=0,maxlen=0;
bool Binary(int k)
{
     bool sign=false;
     int ans1=0;
      for(int i=1; i<=len-k+1; i++)
      {
          int l1=i,r1=i+k-1, l2=len-(i+k-1)+1,r2=len-i+1;
        //     cout<<"L  "<<l1<<"  "<<r1<<"  "<<l2<<" "<<r2<<endl;
            ull t1=get1(l1,r1 ), t2= get2(l2,r2);
            //   cout<<"T  "<<t1<<" "<<t2<<endl;
            if(t1==t2)
            {
                ans1++;
                sign=true;
            }
        }

        if(sign)
        {//cout<<"T  "<<k<<"  "<<sign<<"  "<<maxlen<<endl;
            if(maxlen<k )
            {
                ans=ans1;
                maxlen=k;

            }
            return true;
        }
        return false;

}

int main()
{
    int t;

    Power_generate();
    scanf("%d",&t);
    while(t--)
    {
        maxlen=0,ans=0;
        scanf("%s",s);
        len=strlen(s);
        if(len<=2)
        {
            if(len==1)printf("1 1\n");
            else
            {
                if(s[0]==s[1])printf("2 1\n");
                else printf("1 2\n");
            }
            continue;
        }
        Hashing();

        int left=1,right=len;
        int mid=0;
        while(left<=right)
        {
            mid=(left+right)/2;

            int kk=mid*2;
            if(Binary(kk))
            {
                left=mid+1;
            }
            else right=mid-1;
        }

        left=1,right=len;
        while(left<=right)
        {
            mid=(left+right)/2;
            int kk=mid*2+1;
            if(Binary(kk))
            {
                left=mid+1;
            }
            else right=mid-1;
        }
     //  cout<<ans<<"  "<<maxlen<<"  "<<endl;
       if(maxlen==0)  printf("%d %d\n",1,len);
       else printf("%d %d\n",maxlen,ans);
    }
}
