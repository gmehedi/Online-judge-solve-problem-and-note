#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int Merge(int a[], int left, int mid,int right)
{
    int len1=mid-left+1;
    int len2=right-mid;
    int lef[len1+2],righ[len2+2];
    int i=0,j=0,k=left;
    while(i<len1)  lef[i]=a[left+i],i++;
    while(j<len2) righ[j]=a[mid+j+1],j++;
    i=0,j=0,k=left;
    while(i<len1 && j<len2)
    {
        if(lef[i]<righ[j]) a[k++]=lef[i++];
        else a[k++]=righ[j++],ans+=(len1-i);
    }
    while(i<len1)a[k++]=lef[i++];
    while(j<len2)a[k++]=righ[j++];
}
int Merge_sort(int a[], int left, int right)
{
    if( left<right )
    {
        int mid=(left+right)/2;
        Merge_sort(a,left,mid);
        Merge_sort(a,mid+1,right);
        Merge(a,left,mid,right);
    }
}

int main()
{
    int n;

    while( scanf("%d",&n ) != EOF)
    {
        int a[n+1];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        ans=0;
        Merge_sort(a,0,n-1);
        printf("Minimum exchange operations : %lld\n",ans);
    }
    return 0;
}

