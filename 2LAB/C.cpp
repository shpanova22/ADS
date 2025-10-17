#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int a){
        data=a;
        next=nullptr;
    }
};

class Queue{
private:
    int size;
    Node* head;
    Node* tail;

public:
    Queue(){
        size=0;
        head=tail=nullptr;
    }
    ~Queue(){
        while(!empty()){
            pop();
        }
    }
    void push(int a){
        Node* n = new Node(a);
        if(head==nullptr){
            head=tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        size++;
    }
    void pop(){
        if(empty()){
            cout<<"Empty";
            return;
        }
        Node* old=head;
        head=head->next;
        if(head==nullptr){
            tail=nullptr;
        }
        delete old;
        size--;
    }
    int front(){
        if(empty()){
            return -1;
        }
        return head->data;
    }
    bool empty() {
        return size==0;
    }
    int sz(){
        return size;
    }
};
int main(){
    int k;
    cin>>k;
    Queue arr;
    
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        arr.push(x);
    }
    int index=1;
    while(!arr.empty()){
        if(index%2!=0){
            cout<<arr.front()<<" ";
            arr.pop();
        }
        else{
            arr.pop();
        }
        index++;
    }
    return 0;

}