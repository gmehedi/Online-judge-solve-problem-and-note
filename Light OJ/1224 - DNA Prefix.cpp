
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
# define ll  long long
using namespace std;

map<char,int>mp;
void init()
{
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
}
struct node
{
    ll number,length;
    node* next[5];
    node()
    {
        for(int i=0; i<=3; i++) next[i]=NULL;
        number=0;
        length=0;
    }
} *trie;

void Trie(char *s, int len)
{
    node* curr= trie;
    for(int i=0; i<len; i++)
    {
        int path=mp[s[i]];
        if(curr->next[path] == NULL)
        {
            curr->next[path]=new node();
            curr=curr->next[path];
            curr->length=i+1;
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
    for(int i=0; i<=3; i++) if(curr->next[i] != NULL) del(curr->next[i]);
    delete(curr);
}

ll Search(string s, int len)
{
    ll maxi=0;
    node* curr= trie;
    for(int i=0; i<len; i++)
    {
        int path= mp[s[i]];
        curr=curr->next[path];
       // cout<<"C  "<<curr->number<<"  "<<curr->length<<endl;
        maxi=max(maxi,(curr->number*curr->length));
    }

    return maxi;

}

int main()
{
    init();
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
             char t[60];
             scanf("%s",t);
             s[i]=(string)t;
             int len=(int)strlen(t);
             Trie(t,len);
        }
        ll ans=0;
        for(int i=0; i<n; i++)
        {
            int len=s[i].size();
            ans=max(ans,Search(s[i],len));
        }
        printf("Case %d: %lld\n",cas++,ans);
        del(trie);
    }

    return 0;
}
