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


int max_find(int a[], int m)
{
    int maxi=0,i=0;
    stack<int>st;
    int diff=0;
    while(i<m)
    {
        if( st.empty() ) st.push(i++);
        else if(a[st.top()] <= a[i]) st.push(i++);
        else
        {
            int top=st.top();
            st.pop();
            if( st.empty() ) diff=i;
            else diff= i-st.top()-1;
            // cout<<"T1  "<<st.top()<<"   "<<top<<"  "<<i-st.top()-1<<"  "<<i-top<<endl;
            maxi=max(maxi,diff*a[top]);
        }
     //   cout<<"A  "<<a[i]<<endl;
    }

    while( !st.empty() )
    {
        int top=st.top();
        st.pop();
        if( st.empty() ) diff=i;
        else diff=i-st.top()-1;
        // cout<<"T  "<<st.top()<<"  "<<top<<endl;
        maxi=max(maxi,diff*a[top]);
    }

    return maxi;
}

int solve(int a[120][120], int n, int m)
{
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] != 0) a[i][j]+=a[i-1][j];
        }
    }

    int result=0;
    for(int i=0; i<n; i++)
    {
        result = max( result,max_find(a[i],m) );
    }
    return result;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[120][120];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("%d\n",solve(a,n,m));

    return 0;
}

