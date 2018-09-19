
// M M Mehedi Hasan
// From BUBT
#include<bits/stdc++.h>
# define ll  long long

using namespace std;

struct node
{
    ll number,length;
    node* next[5];
    bool endmark;

    node()
    {
        for(int i=0; i<=5; i++) next[i]=NULL;
        number=1;
        length=0;
        endmark=false;
    }
} *trie;


ll Trie(string &s, ll &len)
{
    node* curr= trie;
    ll maxi=0;
    for(int i=0; i<len; i++)
    {
        int path=s[i]-'0'+1;
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
       ll len2=curr->length, num2=curr->number;

     // cout<<"T  "<<len2<<" "<<num2<<"  "<<curr->length<<"  "<<curr->number<<endl;
    maxi=max(maxi,(num2*len2) );

    }
    return max(len,maxi);
}

void del(node* curr)
{
    for(int i=0; i<=5; i++) if(curr->next[i] != NULL) del(curr->next[i]);
    delete(curr);
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
        ll maxi=0;
       // cout<<"N "<<n<<endl;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            ll len= (int)s.size();
            maxi=max(maxi,Trie(s,len));
        }
        printf("%lld\n",maxi);
        del(trie);
    }

    return 0;
}
