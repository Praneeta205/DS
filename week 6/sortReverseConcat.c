#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL,*second=NULL;
void display(struct node *s)
{
    while(s!=NULL)
    {
        printf("%d\t",s->data);
        s=s->next;
    }
}
void create1(int a[],int n)
{
    struct node *last,*t;
    first=(struct node *) malloc (sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node *) malloc (sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}
void create2(int a[],int n)
{
    struct node *last,*t;
    second=(struct node *) malloc (sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++)
    {
        t=(struct node *) malloc (sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}
void reverse(struct node *p)
{
    struct node *q,*r;
    p=first;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;

    }
    first=q;
}
struct node* concatat(struct node *p,struct node *q)
{
    struct node *r;
    if(p==NULL)
    {
        p=q;
        return p;
    }
    if(q==NULL)
    {
        return q;
    }
    r=p;
    while(r->next!=NULL)
        r=r->next;
    r->next=q;
    return p;

}
void sort(struct node *p)
{
    struct node *i,*j;
    int temp;
    for(i=p;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }

    }
}
void main()
{
    int a[10],b[10],n1,n2;
    printf("enter n:");
    scanf("%d",&n1);
    printf("enter the values");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    struct node *s;
    s=(struct node *) malloc (sizeof(struct node));
    create1(a,n1);
    sort(first);
    printf("sorted list");
    display(first);
    reverse(first);
    printf("\nreversed list");
    display(first);
    printf("\nenter n:");
    scanf("%d",&n2);
    printf("enter the values");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    create2(b,n2);
    display(second);
    s=concatat(first,second);
    display(s);




}