#include <stdlib.h>
#include <stdio.h>

struct node 
{
    int data;
    struct node *next;
}*head=NULL;

void delbeg (struct node *a)
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("node deleted from beginning");

    }
}
void delend (struct node *a)
{
    struct node *ptr,*ptr1;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("only one node is present and its deleted");
    }
    else
    {   
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
        printf("element deleted at the end");

    }
}
void delpos (struct node *a,int pos)
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else{
        int loc=pos;
        struct node *ptr,*ptr1;
        ptr=head;
        if (loc == 1) 
        {
            head = ptr->next; 
            free(ptr);
            printf("Deleted at position %d\n", loc);
            return;
        }
        for(int i=0;i<loc-1;i++)
        {
            ptr1=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("there are less than %d elements",loc);
                return;

            }
        }
        ptr1->next=ptr->next;
        free(ptr);
        printf("deleted at %d",loc);
       
       
        
    }
}
void display(struct node *s)
{
    while(s!=NULL)
    {
        printf("%d\t",s->data);
        s=s->next;
    }
}
void create(int a[],int n)
{
    struct node *last,*t;
    head=(struct node *) malloc (sizeof(struct node));
    head->data=a[0];
    head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(struct node *) malloc (sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}
void main()
{
    int a[10],n;
    printf("enter n:");
    scanf("%d",&n);
    printf("enter the values");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    create(a,n);
    int c,l;
    while(1)
    {
        printf(" menu \n 1.delete from beg 2.del from end 3.del at specific pos 4.display 5.exit ");
        printf("enter the choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:delbeg(head);
                    break;
            case 2:delend(head);
                    break;
            case 3:printf("enter the loc");
            scanf("%d",&l);
                    delpos(head,l);
                    break;
            case 4:display(head);
                    break;
            case 5:exit(0);
            default:printf("invalid input");
                    break;
            
        }
    }
}