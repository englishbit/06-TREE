#include<stdio.h>
#include<stdlib.h>
//logic for defining the structure
struct node{
    int data;
    struct node* left;
    struct node* mid;
    struct node* right;

};


//logic for creating a node
struct node* create(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("the memoery allocation is failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data=data;
    new_node->left=NULL;
    new_node->mid=NULL;
    new_node->right=NULL;
    return new_node;
}


//logic for inserting elements
struct node* insert(struct node* root,int data){
    if(root==NULL){
        return create(data);
    }

        if(data==root->data){
            root->mid=insert(root->mid,data);
        }else if(data<root->data){
            root->left=insert(root->left,data);
        }else{
            root->right=insert(root->right,data);
        }
    return root;
}



int main(){
    struct node* root=NULL;
    root=insert(root,5);
    root=insert(root,8);
    root=insert(root,6);
    root=insert(root,2);
    root=insert(root,7);


  
    return 0;
}