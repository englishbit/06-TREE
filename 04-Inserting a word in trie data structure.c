#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 26


//logic for defining a structure
struct trie_node{
    struct trie_node* alphabet[MAX];
    bool flag;
};


//logic for creating a node in trie ds
struct trie_node* create(){
    struct trie_node* node=(struct trie_node*)malloc(sizeof(struct trie_node));

    if(node==NULL){
        printf("The memory allocation is failed\n");
        exit(EXIT_FAILURE);
    }
    node->flag=false;
    for(int i=0;i<MAX;i++){
        node->alphabet[i]=NULL;
    }
    return node;
}

//logic for inserting a word in trie
void insert(struct trie_node* root,const char *word){
    struct trie_node* current=root;
    while(*word){
        int index=*word-'a';
        if(!current->alphabet[index]){
            current->alphabet[index]=create();
        }
        current=current->alphabet[index];
        word++;
        
    }
    current->flag=true;
}

int main(){
    struct trie_node *root=create();
    
    insert(root,"banana");
    insert(root,"mango");
    insert(root,"computer");

    return 0;
}