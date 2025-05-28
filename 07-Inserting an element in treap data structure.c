#include<stdio.h>
#include<stdlib.h>
//logic for defining the node
struct node{
    int key;
    int priority;
    struct node* left;
    struct node* right;
};


//logic for creating a node
struct node* create(int key){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->key=key;
    new_node->priority=rand()%100;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;

}

//logic for inserting element
struct node* insert(struct node* root ,int key){
    if(root==NULL){
        return create(key);
    }



      if(key<root->key){
        root->left=insert(root->left,key);
        //logic for right rotation          
        if(root->left->priority>root->priority){
            struct node* newroot=root->left;
            root->left=newroot->right;
            newroot->right=root;
            return newroot;
            }
     }else{
        root->right=insert(root->right,key);
        //logic for left rotation
        if(root->right->priority>root->priority){ 
            struct node* newroot=root->right;
            root->right=newroot->left;
            newroot->left=root;
            return newroot;
        }

     }

     
    return root;
}



int main(){

    struct node* root = NULL;

    // Insert elements into the treap
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);



    return 0;
}