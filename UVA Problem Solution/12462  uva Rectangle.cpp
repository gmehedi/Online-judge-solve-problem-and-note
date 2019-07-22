
//M M Mehedi Hasan
//From BUBT
#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define ull               unsigned long long
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define intlim           2147483648
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define maxl 100010

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

bool Check(int color[maxl], int &c, int &left, int &right)
{
    int diff=(right-left)+1,cnt=0;
    if(diff<c) return false;
    map<int,int>mp;

    while(left<=right)
    {
        if(mp[color[left]] == 0) cnt++, mp[color[left]]=1;
        if(cnt ==c ) return true;
        left++;
   }
   return   false;
}

ull Solve(int hist[maxl], int color[maxl], int &n, int &c)
{
    ull maxi=0,diff=0,temp=0;
    int left=0,right=0,top=0,i=0;
    stack<int>st;

    while(i<n)
    {
        if(st.empty() || hist[i]>= hist[st.top()] ) st.push(i++);
        else
        {
            top=st.top();
            temp=hist[top];
            st.pop();

            if(st.empty() ) diff=i, left=0;
            else diff=i-st.top()-1, left=st.top()+1;

            right=i-1;

            if(maxi<(temp*diff) && Check(color,c,left,right) )
            {
                maxi= temp*diff;
                //cout<<"left  "<<left<<"  "<<right<<"  "<<temp<<" "<<diff<<endl;
            }

        }
    }

    while( !st.empty() )
    {
        top=st.top();
        st.pop();
        temp=hist[top];

        if(st.empty()) diff=i, left=0;
        else diff=i-st.top()-1, left=st.top()+1;
        right=i-1;
        if(maxi<(temp*diff) && Check(color,c,left,right) )
        {
            maxi= temp*diff;  //cout<<"LL  "<<left<<"  "<<right<<"   "<<diff<<"  "<<temp<<"  "<<i<<"  "<<st.top()<<endl;
        }
    }

    return maxi;
}

int main()
{
    int n,c;

    while( scanf("%d %d",&n,&c)==2 )
    {
        if(n==0 && c==0) break;
        int hist[n+2],color[n+2];
        for(int i=0; i<n; i++) scanf("%d",&hist[i]);
        for(int i=0; i<n; i++) scanf("%d",&color[i]);

        printf("%llu\n",Solve(hist,color,n,c));
    }

    return 0;
}
