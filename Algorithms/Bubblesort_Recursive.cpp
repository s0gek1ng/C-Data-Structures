#include<bits/stdc++.h>
using namespace std;
void bsort(int a[],int n){
    if(n==1)
        return;
    if(a[0]>a[1]){
        int x=a[0];
        a[0]=a[1];
        a[1]=x;
    }
    bsort(a+1,n-1);
}
void bubblesort(int a[],int n){
    if(n==1)
        return;
    bsort(a,n);    
    bubblesort(a,n-1);
}
void bubbsort(int a[],int j,int n){
    if(n==1)
        return;
    
    if(j==n-1)
        return bubbsort(a,0,n-1);
        
    if(a[j]>a[j+1]){
        int x=a[j];
        a[j]=a[j+1];
        a[j+1]=x;
    }
    bubbsort(a,j+1,n);
}


int main(){
    int a[]={4,3,2,1,5};   
    int n=sizeof(a)/sizeof(int);
    bubbsort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}