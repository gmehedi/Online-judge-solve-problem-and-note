
#include<bits/stdc++.h>
#define sf(a)            scanf("%d",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define x first
#define y second
using namespace std;

const int block_sz=999;
const int maxl= 500010;
int val[maxl],a[maxl],freq[maxl],block[1110],res[maxl],sum=0,n,q;
int l=0,r=-1,i,j,k;

bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	int num = a.x.x / block_sz;
	if (num != b.x.x / block_sz)
		return a.x.x < b.x.x;
	if (num & 1)
		return a.x.y < b.x.y;
	return a.x.y > b.x.y;
}
inline void add(int &v)
{
    ++freq[v];
    if(freq[v] == 1) ++sum, ++val[v], ++block[v/block_sz];
    else if(freq[v] == 2) --sum, --val[v], --block[v/block_sz];
}

inline void substruct(int &v)
{
    --freq[v];
    if(freq[v] == 1) ++sum, ++val[v], ++block[v/block_sz];
    else if(freq[v] == 0) --sum, --val[v], --block[v/block_sz];
}
pair< pair<int, int>, int> qv[maxl];
int get()
{
    if(sum == 0) return 0;
    for( k=0; k<=block_sz; ++k) if(block[k]) for( j=k*block_sz; ; ++j) if(val[j]>0) return j;
    return 0;
}
int main()
{
    sf(n);
    for( i=0; i<n; ++i) sf(a[i]);

    sf(q);
    for( i=0; i<q; ++i)
    {
        sff(qv[i].x.x,qv[i].x.y);
        qv[i].y=i;
    }
    sort(qv, qv+q, compare);
    for( i=0; i<q; ++i)
   {
       int L=qv[i].x.x, R=qv[i].x.y, pos=qv[i].y;
       --L, --R;
       while(l<L) substruct(a[l]), ++l;
       while(l>L) --l, add(a[l]);
       while(r<R) ++r, add(a[r]);
       while(r>R) substruct(a[r]), --r;
       res[pos]=get();
   }
   for( i=0; i<q; ++i ) printf("%d\n",res[i]);
   return 0;
}
