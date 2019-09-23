#include<bits/stdc++.h>
using namespace std;

struct stcknode{
    int data;
    stcknode *next;
};

bool isempty(stcknode* n){
    if(n==NULL)
        return true;
    else
        return false;
}

void push(stcknode* *n,int data){
    stcknode *temp=(stcknode*)malloc(sizeof(stcknode));
    temp->data=data;
    temp->next=*n;
    *n=temp;
}

int pop(stcknode* *n){
    if(isempty(*n))
        return -999999;
        
    stcknode *temp=*n;
    *n=temp->next;
    int x=temp->data;
    free(temp);
    return x;
}
int peek(stcknode* n){
    if(isempty(n))
        return -999999;
    return n->data;
}

int main(){
    stcknode *a=NULL;  
    push(&a,5);
    push(&a,3);
    push(&a,6);
    push(&a,1);
    push(&a,2);
    pop(&a);
    pop(&a);
    pop(&a);
    pop(&a);
    cout<<peek(a);
    return 0;
}