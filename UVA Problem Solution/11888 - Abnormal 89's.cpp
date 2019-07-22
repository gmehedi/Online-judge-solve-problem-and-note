
#include<bits/stdc++.h>
#define maxl 200100
#define maxp 200110
#define p1 31
#define p2 51
using namespace std;

long long power[maxp];
long long mod1 = 1e7+7,mod2=1e9+7;
long long cum[maxl],cum1[maxl];
void Power_generate()
{
    power[0]=1;
    for(long long i=1; i<=maxp; i++)
    {
        power[i]= ((power[i-1])*p1 )%mod1;
    }
}

void Hashing(char *s, long long len,char *s1)
{
    long long value=0,value1=0;
    cum[0]=0,cum1[0]=0;
    for(int i=0; i<len; i++)
    {
        int temp= (s[i]-'a')+1;
        value= ( value+(temp*power[i]) )%mod1;
        cum[i+1]=value%mod1;

        int temp1= (s1[i]-'a')+1;
        value1= ( value1+(temp1*power[i]) )%mod1;
        cum1[i+1]=value1%mod1;
    }
}

long long len;

long long get1(long long l,long long r)
{
    long long po=maxp-l;
  //  cout<<"G  "<<po<<"   "<<l<<"  "<<r<<endl;
    return ( (power[po]*(cum[r]-cum[l-1])%mod1)+mod1)%mod1;
}


long long get2(long long l,long long r)
{
    long long po=maxp-l;
    //cout<<"d "<<po<<"   "<<l<<" "<<r<<endl;
    return ( (power[po]*(cum1[r]-cum1[l-1])%mod1 )+mod1)%mod1;
}

int main()
{
    Power_generate();
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        char s[maxl];
        scanf("%s",s);
        len=strlen(s);
        char s1[maxl];
        int k=0;
        for(int i=len-1; i>=0; i--) s1[k++]=s[i];
        s1[k]='\0';
        Hashing(s,len,s1);

        bool alind=false;
      //  for(int i=0; i<=len; i++) cout<<"G  "<<cum[i]<<"  "<<cum1[i]<<endl;
        for(int i=1; i<=len-1; i++)
        {
            long long t1=get1(1,i),t2= get2(len-i+1,len) , t3=get1(i+1,len) , t4=get2(1,len-i);
            if(t1==t2 && t3==t4)
            {
                alind=true;
                break;
            }

        }

        if(alind) printf("alindrome\n");
        else
        {
            if(cum[len-1] == cum1[len-1]) printf("palindrome\n");
            else printf("simple\n");
        }
    }
    return 0;
}
