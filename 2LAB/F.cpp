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
    Node* head;
    Node* tail;
    int size;
public:
    Queue(){
        head=tail=nullptr;
        size=0;
    }
    ~Queue(){
        while(!empty()){
            pop();
        }
    }
void push(int a){
    Node* n= new Node(a);
    if(tail==nullptr){
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
    delete old;
    size --;
}
int front(){
    if(empty()){
        return -1;
    }
    return head->data;
}

bool empty() {return size==0;}
int sz(){
    return size;
}

void insertAt(int pos, int num){
    if(pos<0 || pos>size){
        cout<<"Error";
        return;
    }
    Node* n= new Node(num);
    if(pos==0){
        n->next=head;
        head=n;
        if(tail==nullptr) tail=n;
    }
    else{
        Node* current=head;
        for(int i=0; i<pos-1; i++){
            current=current->next;
        }
        n->next=current->next;
        current->next=n;
        if(n->next==nullptr){
            tail=n;
        }
    }
    size++;
}
};
int main(){
    int k;
    cin>>k;
    Queue arr;
    for(int i=0; i<k; i++){
        int m;
        cin>>m;
        arr.push(m);
    }
    int num, pos;
    cin>>num;
    cin>>pos;

    arr.insertAt(pos,num);
    while(!arr.empty()){
        cout<<arr.front()<< " ";
        arr.pop();
    }
    return 0;


}