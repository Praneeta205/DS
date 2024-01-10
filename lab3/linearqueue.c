#include <stdio.h>
#include <stdlib.h>
#define max 4
int rear=-1;
int front=-1;
int q[max];
void enqueue(int x)
{
    if (rear==max-1)
    {
        printf("queue overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else{
        rear++;
    }
    q[rear]=x;
}
int dequeue()
{ 
    int x=-1;
    if (front==-1 || front>rear)
    {
        printf("\nunderflow");
        return -1;
    }
    else
    {
        x=q[front];
        front++;
        if(front>rear)
            front=rear=-1;
        return x;
        
    }
}
void display()
{
    if(front==-1 || front>rear)
    {
        printf("\nunderflow");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",q[i]);
        }
       
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
                // break;

        
        default:printf("invalid\n");
            break;
    }
}
}