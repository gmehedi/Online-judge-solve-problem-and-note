
#include<bits/stdc++.h>
#define maxl 150
using namespace std;
struct node
{
    node* next[15];
    bool endmark;
    node()
    {
        endmark=false;
        for(int i=0; i<=15; i++) next[i]=NULL;
    }
} *trie;

bool Build_trie(string s, int len)
{
     node* curr=trie;
     bool sign=false;
    for(int i=0; i<len; i++)
    {
        int path=(s[i]-'0')+1;
      //  cout<<"P   "<<path<<"   "<<s[i]<<endl;
        if(curr->next[path] == NULL)
        {
            curr->next[path]= new node();
            sign=true;
        }
        curr=curr->next[path];
        if(curr->endmark) return false;
    }
    curr->endmark=true;
    if(!sign) return false;
    return true;
}

void del(node* curr)
{
    for(int i=0; i<=12; i++) if(curr->next[i] != NULL) del( curr->next[i] );
    delete(curr);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char temp[maxl];
        string s[n+2];
        bool sign=false;
        for(int i=0; i<n; i++) scanf("%s",temp), s[i]= (string) temp;

        trie= new node();
        for(int i=0; i<n; i++)
        {
            int len= (int) s[i].size();
            if( ! Build_trie(s[i],len) )
            {
                sign=true;
                break;
            }
        }
        if(sign) printf("NO\n");
        else printf("YES\n");
        del(trie);

    }
    return 0;
}
