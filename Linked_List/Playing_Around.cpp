#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void push(struct node * *n,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=*n;
    *n=temp;
}

void print(struct node * n){
    if(n==NULL){
        cout<<"Empty"<<endl;
        return;
    }
    while(n!=NULL){
        cout<<n->data<<"->";
        n=n->next;
    }    
    cout<<"NULL"<<endl;
    
}

int listlen(struct node *n){
    if(n==NULL) 
        return 0;
        
    return 1+listlen(n->next);
}           

bool search(struct node* n,int key){
    if(n==NULL)
        return false;
    if(n->data==key)
        return true;
    return search(n->next,key);
}

int seek(struct node* n,int index){
    int len=listlen(n);
        if(len<=index)
            return -999999;
    for(int i=0;i<index;i++)
        n=n->next;  
    return n->data;    
}

int main(){
    struct node * head;   
    push(&head,4);
    push(&head,8);
    push(&head,7);
    push(&head,1);
    push(&head,2);
    push(&head,3);
    print(head);
    cout<<seek(head,6)<<endl;
    cout<<listlen(head)<<endl;
    return 0;
}