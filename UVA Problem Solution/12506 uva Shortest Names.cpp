// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
# define ll  long long
using namespace std;

struct node
{
    ll number,length;
    node* next[65];
    bool endmark;
    node()
    {
        for(int i=0; i<=65; i++) next[i]=NULL;
        number=1;
        length=1;
        endmark=false;
    }
} *trie;


void Trie(string &s, ll &len)
{
    node* curr= trie;
    ll maxi=0;
    for(int i=0; i<len; i++)
    {
        int path=s[i]-'a'+1;
        if(curr->next[path] == NULL)
        {
            curr->next[path]=new node();
            curr=curr->next[path];
            curr->length=i+1;
        }
        else
        {
            curr=curr->next[path];
            ++curr->number;
        }

    }
}

void del(node* curr)
{
    for(int i=0; i<=5; i++) if(curr->next[i] != NULL) del(curr->next[i]);
    delete(curr);
}

ll Name_size(string s, int len)
{
    node* curr= trie;

    for(int i=0; i<len; i++)
    {//cout<<"S  "<<s[i]<<endl;
        int path=s[i]-(int)'a'+1;

        curr=curr->next[path];
     //   cout<<curr->number<<"  "<<curr->length<<endl;
        if(curr->number <2 )  return curr->length;
    }

    return curr->length;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        trie=new node();
        scanf("%lld",&n);
        getchar();
        string s[n+2];
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            ll len= (int)s[i].size();
            Trie(s[i],len);
        }
        ll ans=0;
        for(int i=0; i<n; i++)
        {
            ans+= Name_size(s[i],(int)s[i].size());
           // cout<<"A "<<ans<<endl;
        }
        printf("%lld\n",ans);
        del(trie);
    }

    return 0;
}
