#include <iostream>
using namespace std;

bool binarysearch(int a[],int n, int x){
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x){
            return true;
        } 
        else if(a[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    bool result=binarysearch(a,n,x);
    if(result==true){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}

