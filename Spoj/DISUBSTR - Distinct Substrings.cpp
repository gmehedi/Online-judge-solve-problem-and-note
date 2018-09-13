
#include<bits/stdc++.h>
#define maxl 1010
using namespace std;
struct node
{
    bool endmark;
    node* next[65];
    node()
    {
        for(int i=0; i<=55; i++)  next[i]=NULL;
        endmark=false;
    }
}*trie;

long long ans=0;
void insertt(string s, int len)
{
    node* curr=trie;
    for(int i=0; i<len ;i++)
    {
        int path=0;
        if(s[i]>='a' &&s[i]<='z') path=( (int)s[i]-'a'); //0-25
        else path=( (int)s[i]-'A')+26; //26 to........

        if(curr->next[path] == NULL)
        {
            curr->next[path]=new node();
            ans++;
        }
        curr=curr->next[path];
    }
    curr->endmark=true;
}

int del(node* curr)
{
    for(int i=0; i<55; i++)
    if(curr->next[i] != NULL) del(curr->next[i]);
    delete(curr);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        ans=0;
        string s;
        getline(cin,s);
        int len= (int)s.size();
        trie=new node();
        for(int i=0; i<len; i++)
        {
            insertt(s.substr(i),len-i);
        }
        printf("%lld\n",ans);
        del(trie);
    }
}
