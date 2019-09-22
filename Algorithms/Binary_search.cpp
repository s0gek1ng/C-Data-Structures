#include<bits/stdc++.h>
using namespace std;
int recurbs(int a[],int key,int l,int r){
    if(l>r)
        return -1;
    int mid=(l+r)/2;
    if(a[mid]==key)
        return mid;
    else if(a[mid]>key)
        return recurbs(a,key,l,mid-1);
    else
        return recurbs(a,key,mid+1,r);
    
}
int binarys(int a[],int n,int key){
    int l=0,r=n-1;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int main(){
    int a[]={1,2,3,5,6,9};
    int n=sizeof(a)/sizeof(int);
    int k=9;
    int index=recurbs(a,k,0,n-1);
    cout<<index;
    return 0;
}