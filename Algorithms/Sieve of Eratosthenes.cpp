#include<bits/stdc++.h>
using namespace std;

void primeupto(int n){
    int a[n+1];
    for(int i=0;i<=n;i++){
        a[i]=1;
    }
    a[0]=a[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        if(a[i]==1){
            for(int j=i;i*j<=n;j++){
                a[i*j]=0;
            }   
        }
    }

    for(int i=0;i<n+1;i++){
        if(a[i]==1)
            cout<<i<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    primeupto(n);
    return 0;
}