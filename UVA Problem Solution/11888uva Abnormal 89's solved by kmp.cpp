
#include<bits/stdc++.h>
#define maxl 200010
using namespace std;
int phi[maxl];
void prefix_func(char pattern[maxl],int len)
{
    int j=0;
    phi[j]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && pattern[i] != pattern[j]) j=phi[j-1];
        if(pattern[i] == pattern[j]) j++;
        phi[i]=j;
    }
}

void kmp(char text[maxl+maxl], char pattern[maxl], int len)
{
    prefix_func(pattern,len);
    int j=0;
    bool alind=false, palind=false;
    for(int i=0; i<len+len; i++)
    {
        while(j>0 && text[i] != pattern[j]) j=phi[j-1];
        if(text[i] == pattern[j]) j++;

        if(len==j)
        {
            //cout<<"G  "<<i+1<<"  "<<pattern[j]<<"  "<<text[i]<<endl;
            if(i+1 != len && i+1 != len+len){ alind=true; break; }
            else palind=true;
        }

    }

    if(alind) printf("alindrome\n");
    else if(palind) printf("palindrome\n");
    else printf("simple\n");

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[maxl+maxl];
        scanf("%s",s);
        int len=strlen(s);
        char revs[maxl];
        strcpy(revs,s);
        int j=len-1,i;
        for( i=0; i<len/2; i++,j--) swap(revs[i],revs[j]);
        for( i=0; i<len; i++) s[i+len]=s[i];
        s[i+len]='\0';

        kmp(s,revs,len);

    }
    return 0;
}
