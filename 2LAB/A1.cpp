#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int n){
        data=n;
        next=nullptr;
    }
};
int main(){
    int n;
    cin>>n;

    Node* head=nullptr;
    Node* tail=nullptr;

    for(int i=0; i<n;i++){
        int value;
        cin>>value;
        Node* node=new Node(value);
        if(!head) head =tail=node;
        else{
            tail->next=node;
            tail=node;
        }
    }

    int target;
    cin>>target;
    
    int bestIndex=0;
    int minDist=abs(head->data-target);

    Node*cur=head->next;
    int currentPos=1;

    while(cur!=nullptr){
        int dist=abs(cur->data-target);
        if(dist<minDist){
            minDist=dist;
            bestIndex=currentPos;
        }
        cur=cur->next;
        currentPos++;
    }
    cout<<bestIndex;
    return 0;

}