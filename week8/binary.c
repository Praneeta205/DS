#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    }*root=NULL;
struct node *create(struct node *t,int ele){

    if(t==NULL){
        struct node *temp=(struct node *) malloc (sizeof(struct node));
        temp->data=ele;
        temp->left=temp->right=NULL;
        return temp;
    }
    else{
            if(ele<t->data){
                t->left=create(t->left,ele);
            }
            else{
                t->right=create(t->right,ele);
            }

    }
    return t;
}
void pre(struct node *root){
    struct node *r;
    r=root;
    if(r!=NULL){
        printf("%d\t",r->data);
        pre(r->left);
        pre(r->right);
    }
}
void in(struct node *root){
    struct node *r;
    r=root;
    if(r!=NULL){

        in(r->left);
        printf("%d\t",r->data);
        in(r->right);
    }
}

void post(struct node *root){
    struct node *r;
    r=root;
    if(r!=NULL){

        post(r->left);
        post(r->right);
        printf("%d\t",r->data);
    }
}
void main(){
    int n,ele;
    printf("enter the no of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the element %d:",i+1);
        scanf("%d",&ele);
        root=create(root,ele);
    }
    printf("display the elements in preorder traversal:");
    pre(root);
    printf("\ndisplay the elements in inorder traversal:");
    in(root);
    printf("\ndisplay the elements in postorder traversal:");
    post(root);

}
