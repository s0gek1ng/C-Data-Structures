#include<bits/stdc++.h>
using namespace std;

struct que{
    int front,rear;
    int capacity;
    int *arr;
};

struct que* createque(int size){
    struct que *temp=(struct que*)malloc(sizeof(struct que));
    temp->front=-1;
    temp->rear=-1;
    temp->capacity=size;
    temp->arr=(int*)malloc(temp->capacity*sizeof(int));
    
    return temp;
}

bool isempty(struct que* Q){
    if(Q->front==-1)
        return true;
    return false;    
    
}
bool isfull(struct que* Q){
    if((Q->rear+1)%Q->capacity==Q->front)
        return true;
    return false;
}
void enque(struct que *Q,int data){
    if(isfull(Q)){
        cout<<"que full"<<endl;
        return;
    }
    Q->rear=(Q->rear+1)%Q->capacity;  
    Q->arr[Q->rear]=data;
    if(Q->front==-1)
        Q->front=Q->rear;
        
    return;
}
int deq(struct que* Q){
    int data;
    if(isempty(Q)){
        cout<<"que is Empty"<<"\n";
        return 0;
    }
    else{
        data=Q->arr[Q->front];
        if(Q->rear==Q->front)
            Q->front=Q->rear=-1;
        else
            Q->front=(Q->front+1)%Q->capacity;
    }
    return data;
}

int main(){
    struct que* q=createque(100);
    int x;
    for(int i=0;i<5;i++){
        cin>>x;
        enque(q,x);
    }
    cout<<deq(q)<<"\n";
    cout<<deq(q)<<"\n";
    return 0;
}