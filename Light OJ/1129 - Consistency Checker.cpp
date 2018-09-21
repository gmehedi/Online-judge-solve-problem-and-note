
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
# define ll  long long
using namespace std;

struct node
{
    int number;
    node* next[13];
    node()
    {
        for(int i=0; i<=12; i++) next[i]=NULL;
        number=0;
    }
} *trie;

void Trie(char *s, int len)
{
    node* curr= trie;
    for(int i=0; i<len; i++)
    {
        int path=s[i]-48;
        if(curr->next[path] == NULL)
        {
            curr->next[path]=new node();
            curr=curr->next[path];
        }
        else
        {
            curr=curr->next[path];
        }
        curr->number++;
    }

}

void del(node* curr)
{
    for(int i=0; i<=12; i++) if(curr->next[i] != NULL) del(curr->next[i]);
    delete(curr);
}

bool Search(string s, int len)
{
    node* curr= trie;
    for(int i=0; i<len; i++)
    {
        int path=s[i]-48;
        curr=curr->next[path];
    }
  //  cout<<"C  "<<curr->number<<endl;
    if(curr->number>=2) return true;
    return false;

}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        trie=new node();
        scanf("%d",&n);

        string s[n+2];
        for(int i=0; i<n; i++)
        {
             char t[20];
             scanf("%s",t);
             s[i]=(string)t;
             int len=(int)strlen(t);
             Trie(t,len);
        }
        bool sign=true;
        for(int i=0; i<n; i++)
        {
            int len=s[i].size();
            if(Search(s[i],len))
            {
                printf("Case %d: NO\n",cas++);
                sign=false;
                break;
            }
        }
        if(sign) printf("Case %d: YES\n",cas++);
        del(trie);

    }

    return 0;
}
