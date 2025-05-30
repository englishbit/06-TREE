#include<stdio.h>
#include<stdlib.h>

//logic for defining the structure
struct node{
    int key;
    int priority;
    struct node* left;
    struct node* right;
}

//logic for creating node
struct node* create(int key){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->key=key;
    newnode->priority=rand()%100;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;

}

//logic for inserting a node in treap 
struct node* insert(struct node* root,int key){

    if(root==NULL){
        return create(key);
    }

    
    if(key<root->key){

        //logic for right rotation
        root->left=insert(root->left,key);
        if(root->left->priority>root->priority){
                struct node* newroot=root->left;
                root->left=newroot->right;
                newroot->right=root;
                return newroot;
        }
    }else{
        root->right=insert(root->right,key);

        //logic for right rotation
        if(root->right->priority>root->priority){
                struct node* newroot=root->right;
                root->right=newroot->left;
                newroot->left=root;
                return newroot;
        }
    }

    return root;
}

//logic for searching an element

    struct node* search(struct node* root,int key){
        if(root==NULL || key==root->key){
            return root;
        }

        if(key<root->key){
            return search(root->left,key);
        }else{
            return search(root->right,key);
        }
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


    int value;
    scanf("%d",&value);

    if(search(root,value)!=NULL){
        printf("The key is found\n");
    }else{
        printf("The key is not found\n");
    }


    
    return 0;
}