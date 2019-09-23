#include<bits/stdc++.h>
using namespace std;

struct stck{
  int top;
  int capacity;
  int *array;
};

struct stck * createstack(int capacity){
    struct stck *temp=(struct stck*)malloc(sizeof(struct stck));
    temp->top=-1;
    temp->capacity=capacity;
    temp->array=(int *)malloc(temp->capacity*sizeof(int));
    return temp;
}

int isempty(struct stck * n){
    return n->top==-1;
}

int isfull(struct stck *n){
    return n->top==n->capacity-1;
}

void push(struct stck* n,int data){
    if(isfull(n))
        return;
    n->top++;
    n->array[n->top]=data;
    return;
}
int pop(struct stck* n){
    if(isempty(n))
        return -1;
    return n->array[n->top--];    
}
int peek(struct stck* n){
    return n->array[n->top];
}
int main(){
    struct stck * a=createstack(100);
    push(a,10);
    push(a,5);
    push(a,4);
    push(a,3);
    push(a,2);
    cout<<pop(a)<<"\n";
    pop(a);
    pop(a);
    cout<<peek(a)<<"\n";
    return 0;
}