#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL,*rear=NULL;
void enqueue(int x)
{
    struct node *t;
    t=(struct node*) malloc (sizeof(struct node));
    if(t==NULL)
    {
        printf("overflow");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue()
{
    struct node *t;
    int x=-1;
    if(front==NULL)
    {
        printf("underflow");
        return x;
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        
        free(t);
        return x;

    }


}
void display()
{
    struct node *t;
    // t = (*struct node)malloc(sizeof(struct node));
    t=front;
    while(t)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");

}
void main()
{
    int c, no, x;
    while (1)
    {
        printf("enter 1 for insert 2 for delete 3 for display 4 for exit\n");
        printf("enter the choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter the no:");
            scanf("%d", &no);
            enqueue(no);

            break;
        case 2:
            x = dequeue();
            if (x != -1)
            {
                printf("%d is popped\n", x);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("invalid\n");
            break;
        }
    }
}