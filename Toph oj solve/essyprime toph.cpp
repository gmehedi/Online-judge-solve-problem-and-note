#include<bits/stdc++.h>
#define maxi 10000010
using namespace std;
int n;
bitset<maxi>b;
long long cum[100005];
void Prime()
{
    b[0]=1;
    b[1]=1;
    for(int i=2; i*i<=maxi; i++) if(!b[i]) for(int j=i+i; j<=maxi; j+=i ) b[j]=1;//cout<<b[j]<<"   "<<j<<endl;
   // cout<<"D  "<<b[4]<<"  "<<b[6]<<endl;
}
int a[100004];
void Update(int index,int element)
{//cout<<"EV  "<<b[element]<<"   "<<b[a[index-1]]<<"   " <<element<<endl;
    if( !b[element] && b[a[index-1]])
    {//cout<<"B   "<<element<<"  "<<index<<"    "<<cum[index]<<endl;
        a[index-1]=element;
        for(int i=index; i<=n; i++) cum[i]+=1;
    }
    else if( b[element] && !b[a[index-1]]){ a[index-1]=element; for(int i=index; i<=n; i++)cum[i]-=1; }//cout<<"cu  "<<cum[i]<<endl; }
  // for(int i=0; i<n; i++)cout<<"CM2  "<<cum[i+1]<<endl;
}

int main()
{
    Prime();
    scanf("%d",&n);
    cum[0]=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if( !b[ a[i] ] ) cum[i+1]=1;
        cum[i+1]+=cum[i];
    }
    //for(int i=0; i<n; i++)cout<<"CM  "<<cum[i+1]<<endl;
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        int check,x,y;
        scanf("%d",&check);
        if( check==1 ) { scanf("%d%d",&x,&y),printf("%lld\n",cum[y]-cum[x-1]); }// cout<<"G   "<<cum[y]<<"   "<<cum[x-1]<<endl;}
        else if( check==2 ) { scanf("%d%d",&x,&y),Update(x,y); }
    }

    return 0;
}
