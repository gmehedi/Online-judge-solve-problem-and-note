#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
   int id;
   node *next;
} *start;

class singleList
{
    public:
        node* CreatNode( int data);
        void InsertFst();
        void InsertLast();

        void Show();
        void SelectionSort();
        void InsertionSort();
        void BubbleSort();
        void Deletepos();

        singleLlist()
        {
            start=NULL;
        }

};
struct node *temp ,*p,*ex;
  node* singleList :: CreatNode(int data)
{
    temp=new (struct node);
    if(temp==NULL)
    {
        cout <<"Not allocated"<<endl;
        return 0;
    }
    else
    {
        temp->id=data;
        temp->next=NULL;
        return temp;
    }

};

 void singleList::InsertFst()
 {
   //  struct node *temp;
     int data;
    cin >>data;
     temp=CreatNode(data);
     if(start==NULL)
     {
         start=temp;
         start->next=NULL;
     }
     else
     {
         p=start;
         start=temp;
         start->next=p;
     }
 }

  void singleList :: InsertLast()
  {
      int data;
       cin >>data;
     temp=CreatNode(data);
     temp->next=NULL;
     if(start==NULL)
     {
         start=temp;
         start->next=NULL;

     }
     else
     {
         ex=start;
        while(ex->next!=NULL)
        {
            ex=ex->next;

        }
        ex->next=temp;

     }


  }

 void singleList :: Show()
 {
     temp=start;
     while(temp != NULL)
     {
         cout <<temp->id<<endl;
         temp=temp->next;
     }
 }

  void singleList::SelectionSort()
  {
      p=start;

      while(p != NULL)
      {
            for(ex=p->next; ex != NULL; ex=ex->next )
            {
                if(p->id>ex->id)
                {
                   int t=p->id;
                   p->id=ex->id;
                   ex->id=t;
                }

            }
            p=p->next;
      }

  }

    void singleList::BubbleSort()
    {
        p=start;
        while(p->next != NULL)
        {
            for(ex=p; ex->next != NULL; ex=ex->next)
            {
                struct node *ee;
                ee=ex->next;

                if(ex->id > ee->id)
                {
                   int t=ex->id;
                   ex->id=ee->id;
                   ee->id=t;
                }
            }
            p=p->next;
        }

    }


      void singleList::Deletepos()
      {
          int cnt=0;
          p=start;
          int pos;
          cin >>pos;

          if(pos==0)
          {
              start=p->next;
              free(p);
          }
          else
          {
             while(p!=NULL)
              {
                  cnt++;
                  p=p->next;
              }
          }
          if(pos>0&&pos<=cnt)
          {
             p=start;
             for(int i=0; i<pos; i++)
             {
                 ex=p;
                 p=p->next;

             }
             ex->next=p->next;
             free(p);

          }
          else
          {
              cout <<"Out of Range "<<endl;
          }
      }
int main()
{
    singleList l;
   // int data;
 //   cin >>data;
   // temp= l.CreatNode( data);


  l.InsertLast();
  l.InsertLast();
  l.InsertLast();
  cout <<"Before Sorting "<<endl;
  l.Show();
  cout <<"After sorting "<<endl;
  l.BubbleSort();
    l.Show();
    l.Deletepos();
     cout <<"After delete"<<endl;
        l.Show();
     return 0;
}
