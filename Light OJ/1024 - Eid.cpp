
#include<bits/stdc++.h>
#define maxl 122
#define ll long long
using namespace std;

map<int,int> ans;
void Factorization(int num)
{
    map<int,int>temp;
    int num1=num;
    for(int i=2; i*i<=num; i++)
    {
        if(num1%i == 0)
        {
            int cnt=0;
            while(num1%i == 0) cnt++,num1/=i;
            temp[i]=cnt;
        }
    }

    if(num1>1) temp[num1]=1;
    int len= temp.size();
    map<int,int> :: iterator it;
    it=temp.begin();

    for(int i=0; i<len; i++,it++)
    {
        int ind=it->first;
    //    cout<<"T  "<<ind<<"  "<<temp[ind]<<"  "<<ans[ind]<<endl;
        ans[ind]=max(ans[ind],temp[ind]);
    }
}
int digit[100000];
int sz=1,carry=0,cas=1;

void print()
{
    printf("Case %d: ",cas++);
    for(int i=sz-1; i>=0; i--) printf("%d",digit[i]);
    printf("\n");
}

void Multiply(int num, int power)
{
   // cout<<"N  "<<num<<"  "<<power<<endl;
    for(int i=0; i<power; i++)
    {
        int res= num,carry=0;
        for(int j=0; j<sz; j++)
        {
            res= (num*digit[j])+carry;
            digit[j]=res%10;
            carry=res/10;
       //     cout<<"D  "<<digit[j]<<"  "<<carry<<endl;
        }
        while( carry ) digit[sz++]= carry%10, carry/=10;
    }

}


int main()
{
    int n,num,t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num);
          //  cout<<"I  "<<i<<endl;
            Factorization(num);
        }
        int len=ans.size();

        map<int,int>:: iterator it;
        it=ans.begin();

        digit[0]=1;
        for(int i=0; i<len; i++,it++)
        {
            Multiply(it->first, it->second);
        }

        print();

        ans.clear();
        sz=1;
        carry=0;
        memset(digit,0,sizeof digit);
    }
    return 0;
}
