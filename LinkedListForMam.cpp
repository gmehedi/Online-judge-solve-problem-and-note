#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct node *p,*ex,*start=NULL,*temp,*t,*l;
void Creat_Node()
{
    int value;
    cin >> value;
    temp=new node;
    temp->data=value;
    temp->next=NULL;

}
void Insert()
{
    Creat_Node();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        p=start;
        while(p->next != NULL)p=p->next;
        p->next=temp;

    }

}
void Show()
{
    p=start;
    while(p!=NULL)
    {
        cout <<p->data<<"-->";
        p=p->next;
    }
    cout <<"NULL"<<endl<<endl;

}

void Search()
{
    p=start;
    int srch;
    bool b=0;
    cout <<"Enter the searching element"<<endl;
    cin >> srch;
    while(p!=NULL)
    {
        if(srch==p->data)
        {
            b=1;
            break;
        }
       p=p->next;
    }
    if(b)cout <<p->data<<" The element is found"<<endl;
    else cout <<"Not found"<<endl;
}

void Insert_Position()
{
    p=start;
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    p=start;
    cout <<"Enter ur position"<<endl;
    int pos;
    cin >>pos;
    if(i>=pos)
    {
        Creat_Node();
        if(pos==0)
        {
            ex=start;
            start=temp;
            temp->next=ex;
        }
        else
        {
              for(int i=0; i<pos; i++)
              {
                  ex=p;
                  p=p->next;
              }
              temp->next=p;
              ex->next=temp;

        }
    }
    else cout <<"Does not possible"<<endl;

}

void Delete()
{
    cout <<"Enter element for Delete"<<endl;
    int d,i=0;
    cin >> d;
    p=start;
    while(d !=p->data)
    {
        i++;
        ex=p;
        p=p->next;
    }
    if(i==0)
    {
        start=p->next;
    }
    else
        ex->next=p->next;

}

void Sort()
{
    p=start;
    for(ex=p; ex->next != NULL; ex=ex->next)
    {
        for(t=ex->next; t!=NULL; t=t->next)
        {
            if(ex->data>t->data)
            {
                int temp=ex->data;
                ex->data=t->data;
                t->data=temp;

            }
        }
    }
}
int main()
{
    cout<<"Enter your choice Sadik Vai "<<endl;
    int choice ;

    Insert(8);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(1);
    Insert(5);
    Insert(6);
    Insert(7);
    Show();
    Search();
    Insert_Position();
    Show();
    Delete();
    Show();
    Sort();
    cout <<"After Sorting"<<endl;
    Show();

    return 0;
}
