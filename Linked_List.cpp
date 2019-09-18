#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node * next;
};

struct node * current=NULL;
int cont=0;

//Insert At End
void push(struct node * *n,int x){
    struct node *temp =NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(*n==NULL){
        *n=temp;
        current=*n;
    }
    else{
        current->next=temp;
        current=current->next;
    }
    cont++;
}
//Insert At Beginning
void iab(struct node * *n,int x){
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next= *n;
    *n=temp;
    cont++;
}
//Insert At Random Position 
void iarp(struct node * *n,int x,int pos){
    if(pos==1){
        iab(n,x);
        return;
    }
    if(cont+1>=pos){
        struct node * ptr;
        ptr=*n;
        struct node *temp=NULL;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        for(int i=1;i<pos-1;i++)
            ptr=ptr->next;
        temp->next=ptr->next;
        ptr->next=temp;  
        cont++;
    }
    else if(cont+1<pos){
        cout<<"Out of Bound"<<endl;
    }
   
}

void printlist(struct node* n){
    while(n!=NULL){
        cout<<n->data<<"->";
        n=n->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    struct node *head;
    push(&head,3);
    push(&head,7);
    push(&head,5);
    iab(&head,4);
    iarp(&head,8,2);
    printlist(head);
    cout<<cont<<endl;
    return 0;
}