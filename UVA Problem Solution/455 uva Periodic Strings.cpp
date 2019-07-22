
#include <bits/stdc++.h>
#define maxp 110
using namespace std;
int phi[maxp];
void prefix_kmp(char s2[maxp], int len)
{
    int j=0;
    phi[0]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && s2[i] != s2[j]) j=phi[j-1];
        if(s2[i] == s2[j]) j++;
        phi[i]=j;
    }
  //  for(int i=0; i<len; i++) cout<<phi[i]<<" ";
}

int main()
{
    int t;
    scanf("%d",&t);
    bool b=false;
    while(t--)
    {
        char s1[maxp];
        if(b)printf("\n");
        scanf("%s",s1);
        int len=(int)strlen(s1);
        prefix_kmp(s1,len);
        int period=len-phi[len-1];
        if(len%period==0) printf("%d\n",len-phi[len-1]);
        else printf("%d\n",len);
        b=true;
    }
    return 0;
}
