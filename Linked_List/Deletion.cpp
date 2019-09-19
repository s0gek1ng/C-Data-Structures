#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * next;
};

void push(struct node * *n,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=*n;
    *n=temp;
}

void del(struct node * *n,int key){
    struct node * temp=*n;
    struct node * prev=NULL;
    if(temp==NULL){
        cout<<"Empty list"<<endl;
        return;
        
    }
    if(temp!=NULL && temp->data==key){
        *n=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Key Not Found"<<endl;
        return;
    }

    prev->next=temp->next;
    free(temp);
    
    return;
}


void print(struct node *n){
     
     if(n!=NULL){
        while(n!=NULL){
            cout<<n->data<<"->";
            n=n->next;
        }
        
        cout<<"NULL"<<endl;
     }        
}

int main(){
    struct node * head=NULL;
    push(&head,8);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,9);
    del(&head,9);
    print(head);
    return 0;
}