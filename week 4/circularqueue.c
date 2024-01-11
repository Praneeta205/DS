#include <stdio.h>
#include <stdlib.h>
#define max 10
int rear=-1;
int front=-1;
int q[max];
int isfull()
{
    if(front==rear+1 || front==0 && rear==max-1)
        return 1;
    return 0;
    
}
int is_empty()
{
    if(front==-1 && rear==-1)
        return 1;
    return 0;
}
void enqueue(int x)
{
    if(isfull())
    {
        printf("overflow\t");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%max;
    }
    q[rear]=x;
    


}
int dequeue()
{
    int vlaue=-1;
    if(is_empty())
    {
        printf("underflow\t");
        return -1;
    }
    else
   {
        vlaue=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%max;
    }
    return vlaue;
   } 
}
void display()
{
    int i;
    if(is_empty())
    {
        printf("underflow\t");

    }
    else
    {
        printf("elements are:");
        for( i=front;i!=rear;i=(i+1)%max)
        {
            printf("%d\t",q[i]);
        }
        printf("%d",q[i]);
    }
}
void main()
{ 
    int c,no,x;
    
    while(1)
    {
        printf("enter 1 for insert 2 for delete 3 for display 4 for exit\n");
        printf("enter the choice:");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("enter the no:");
            scanf("%d",&no);
            enqueue(no);
            
            break;
        case 2:x=dequeue();
                if (x!=-1)
                {
                    printf("%d is popped\n",x);
                }
                break;
        case 3:display();
                break;
        case 4:exit(0);
             

        
        default:printf("invalid\n");
            break;
    }
}
}
