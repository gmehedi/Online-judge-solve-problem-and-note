
#include<bits/stdc++.h>
using namespace std;
struct quary
{
    int l;
    int r;
};

bool compare(quary& x, quary& y)
{
    if(x.l/3 != y.l/3)
    {
        return x.l/3<y.l/3;
    }
    return x.r<y.r;
}
vector<quary>v;
int sum=0;
int Mos_alg(int a[], int q_s, int n)
{
    sort(v.begin(),v.end(),compare);
    int c_l=0,c_r=-1;
    for(int i=0; i<q_s; i++)
    {
        int l=v[i].l,r=v[i].r;

       // cout<<"L  "<<l<<"  R   "<<r<<endl;
        while(c_l<l)
        {
            sum -= a[c_l];
            c_l++;
        }

        while(c_l>l)
        {
            c_l--;
            sum+=a[c_l];
        }

        while(c_r<r)
        {
            c_r++;
            sum+=a[c_r];
            //cout<<"S   "<<sum<<"   "<<c_r<<endl;
        }

        while(c_r>r)
        {
           sum-=a[c_r];
            c_r--;
        }


        //cout<<v[i].l<<"  to  "<<v[i].r<<"   ===  "<<sum<<endl;
    }
}
int main()
{
    int n;
    int a[10]={1,1,1,1,1,1,1,1,1,1};
    n=10;
    int q;
    scanf("%d",&q);

    for(int i=0; i<q; i++)
    {
        int l,r;
        cin>>l>>r;
        v.push_back({l,r});
    }
    Mos_alg(a,q,n);

}
