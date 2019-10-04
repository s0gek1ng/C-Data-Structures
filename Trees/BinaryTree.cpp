#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct node* newnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    
    return temp;
}

void preorder(struct node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}


int maxele(struct node* root){
    static int max=-1;
    if(root==NULL)
        return 0;
    if(root!=NULL){
        if(max<root->data)
            max=root->data;
        maxele(root->left);
        maxele(root->right);
    }  
    return max;
}

int search(struct node* root,int item){
    if(root==NULL)
        return 0;
    search(root->left,item);
    search(root->right,item);
    if(item==root->data)
        return 1;
   
   return 0;
}

int main(){
    struct node* root=newnode(5);
    root->left=newnode(3);
    root->right=newnode(4);
    root->left->left=newnode(6);
    root->left->right=newnode(7);
    root->right->left=newnode(8);
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n"<<maxele(root);
    
    return 0;
}