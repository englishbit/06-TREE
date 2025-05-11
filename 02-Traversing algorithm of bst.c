#include<stdio.h>
#include<stdlib.h>
//logic for defining the structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//logic for creating structure function

struct node* create_node(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//logic for inserting function

struct node* insert(struct node* root,int data){
    if(root==NULL){
        return create_node(data);
    }
    if(data<root->data){
           root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }

    return root;
}

//logic for inorder traversal
 void inorder(struct node* root){
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

//logic for preorder traversal
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//logic for postorder traversal
 void postorder(struct node* root){
    if(root!=NULL){
        
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

    }
}

int main(){
    struct node* root=NULL;
    root=insert(root,3);
    
    insert(root,5);
    insert(root,9);
    insert(root,4);

    //logic for printing the tree
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");


    
    return 0;
}