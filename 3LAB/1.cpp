#include <iostream>
#include <vector>

using namespace std;

int binarysearch(vector<int> &arr, int x){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(high+low)/2;
        
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int k;
    cin>>k;
    vector<int> arr(k);

    for(int i=0; i<k; i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;
    int result=binarysearch(arr, x);
    if(result==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<result;
    }
}