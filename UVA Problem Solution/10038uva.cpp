#include<cstdio>
#include<algorithm>
int main()
{
    int n;
    scanf("%d",&n);
    bool t=1;
    int temp;
    scanf("%d",&temp);
    int d=3;

    for(int i=0; i<n-1; i++)
    {
        int num;
        scanf("%d",&num);

        if( abs(temp-num)==d)
        {
            d--;
            temp=num;
        }
        else t=0;

    }
    if(t) printf("jolly\n");
    else printf("Not jolly\n") ;

return 0;
}
