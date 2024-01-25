#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;
int empty()
{
    if (top == NULL)
        return 1;
    return 0;
}
int full()
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) 
        return 1;
    return 0;
}
void push(int x)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));

    if (full())
    {
        printf("overflow");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop()
{
    struct node *t;
    // t = (*struct node)malloc(sizeof(struct node));
    int x = -1;
    if(empty())
    {
        printf("stack underflow");
        return x;
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
        return x;
    }
}
void display()
{
    struct node *t;
    // t = (*struct node)malloc(sizeof(struct node));
    // t=top;
    while(t!=NULL)
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
            push(no);

            break;
        case 2:
            x = pop();
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