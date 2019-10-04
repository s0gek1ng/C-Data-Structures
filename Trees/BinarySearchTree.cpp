#include<bits/stdc++.h>
using namespace std;

struct bst{
    int data;
    bst* left;
    bst* right;
};

void insert(bst* *root,int data){
    bst* k=*root;  
    bst* temp=(bst*)malloc(sizeof(bst));    
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    
    if(*root==NULL){
        *root=temp;
        return;
    }
    bst* current;
    while(k!=NULL){
        current=k;
        if(k->data<data){
            k=k->right;
        }
        else if(k->data>data){
            k=k->left;
        }
    }
    if(current->data<data)
        current->right=temp;
    else if(current->data>data)
        current->left=temp;
}

void print(bst* root){ //Inorder Traversal 
    if(root!=NULL){
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
    }
    return;
}

bst* maxelement(bst* root){
    if(root==NULL)
        return NULL;
    if(root->right==NULL)
        return root;
    maxelement(root->right);   
}

bst* search(bst* root,int data){
    if(root==NULL)
        return NULL;
    if(root->data==data)
        return root;
    else if(root->data>data)
        search(root->left,data);
    else if(root->data<data)
        search(root->right,data);
}



int main(){
    bst* root;
    insert(&root,7);
    insert(&root,9);
    insert(&root,4);
    insert(&root,2);
    insert(&root,5);
    insert(&root,11);
    insert(&root,8);
    insert(&root,1);
    print(root);
    bst *y=maxelement(root);
    cout<<"\n"<<y->data;
    bst* x=search(root,4);
    cout<<"\n"<<x->left->data;
    return 0;
}