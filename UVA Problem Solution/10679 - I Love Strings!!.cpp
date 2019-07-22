
#include <bits/stdc++.h>
#define maxt 101000
#define maxp 1100
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

bool kmp(char s1[maxt], char s2[maxp])
{
    int len1=(int)strlen(s1), len2= (int)strlen(s2);
    prefix_kmp(s2,len2);
    int j=0;
    for(int i=0; i<len1 && j<len2; i++)
    {
        while(j>0 && s1[i] != s2[j] ) j=phi[j-1];
        if(s1[i] == s2[j]) j++;
        if(len2 == j) { return true; }
    }
    return false;
}
int main()
{
    int q,t;
    scanf("%d",&t);
    while(t--)
    {
        char s1[maxt];
        scanf("%s %d",s1,&q);
    //   cout<<"S  "<<s1<<endl;
        for(int i=0; i<q; i++)
        {
            char s2[maxp];

            scanf("%s",s2); //cout<<"SS  "<<s2<<endl;
            if( kmp( s1,s2 ) ) printf("y\n");
            else printf("n\n");
        }
    }
    return 0;
}
