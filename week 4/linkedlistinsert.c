#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL;
void insert(struct node  **p,int pos,int no)
{
    struct node *t;
    t=(struct node*) malloc (sizeof(struct node));
    t->data=no;
    if(pos==0)
    {
        t->next=*p;
        *p=t;
    }
    else{
        struct node *temp=*p;
        for(int i=1;i<pos && (p!=NULL);i++)
            temp=temp->next;
        t->next=temp->next;
        temp->next=t;
       
    }

}
void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    

}
void main()
{
    int ch,p,n;
    while(1)
    {
        printf("enter 1 to insert 2 to display 3 to exit"); 
        printf("enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the   pos and no where to insert:");
                    scanf("%d%d",&p,&n);
                    insert(&first,p,n);
                    break;
            case 2:display(first);
                    break;
            case 3:exit(0);
            default:printf("invalid choice");
                    break;

        }
    }

    
}
