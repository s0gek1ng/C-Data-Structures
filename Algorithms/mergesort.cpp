#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[1000];
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
        }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k]=a[j];
        j++;
        k++;
    }
    for(int i=s;i<=e;i++)
        a[i]=temp[i];
}

void mergesort(int a[],int s,int e){
    if(s>=e)
        return;
    
    int mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    
    merge(a,s,e);
}

int main(){
    int a[6]={6,4,3,5,2,1};
    mergesort(a,0,5);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";

    return 0;
}