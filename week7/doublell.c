#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*first=NULL;
void create(int a[],int n){
    struct node *t,*last;
    first=(struct node *) malloc (sizeof(struct node));
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *) malloc (sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void insertleft(int val,int pos){
    struct node *t,*ptr;
    int i,loc;
    loc=pos;
    t=(struct node *) malloc (sizeof(struct node));
    if(t==NULL){
        printf("overflow");
    }
    t->data=val;
    if(pos==1){
            t->prev=NULL;
            t->next=first;


            if(first!=NULL){
                first->prev=t;
            }
            first=t;

    }

    else
    {
            ptr=first;
            for(int i=0;i<loc-2;i++){
                ptr=ptr->next;
            }
            t->next=ptr->next;
            t->prev=ptr;

            if(ptr!=NULL){
                ptr->next->prev=t;
            }
             ptr->next=t;
    }
    printf("node inserted ");

}
void delevalue(int val){
    struct node *ptr;
    int value;
    value=val;
    ptr=first;
    while(ptr!=NULL){
        if(ptr->data==value){
            if(ptr->prev!=NULL){
                ptr->prev->next=ptr->next;
            }
            if(ptr->next!=NULL){
                ptr->next->prev=ptr->prev;
            }
            if(ptr==first){
                first=ptr->next;
            }
            free(ptr);
        printf("value %d deleted",value);
        return;
        }
        ptr=ptr->next;

    }
    printf("%d value not found",value);

}
void display(struct node *p)
{
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void main(){
    int a[10],n;
    int val,key,loc;
    printf("read n");
    scanf("%d",&n);
    printf("enter the values:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    create(a,n);
    display(first);
    printf("enter the value to be inserted:");
    scanf("%d",&val);
    printf("enter the loc  to be inserted at:");
    scanf("%d",&loc);
    insertleft(val,loc);
    display(first);
    printf("enter the key element to be deleted");
    scanf("%d",&key);
    delevalue(key);
    display(first);
}
