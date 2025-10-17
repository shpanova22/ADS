#include <iostream>
#include <string>
using namespace std;
struct Node{
    string data;
    Node* next;
    Node(string s){
        data = s;
        next = nullptr;
    }
};

class Queue{
private:
    int size;
    Node* head;
    Node* tail;

public:
    Queue(){
        size = 0;
        head = tail = nullptr;
    }
    ~Queue(){
        while(!empty()){
            pop();
        }
    }

    void push(string s){
        Node* n = new Node(s);
        if(tail == nullptr){
            head = tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void pop(){
        if(empty()){
            cout<<"Empty";
            return;
        }
        Node* old = head;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        delete old;
        size--;
    }

    string front(){
        if(empty()){
            return "   ";
        }
        return head->data;
    }

    bool empty(){ return size==0; }

    int sz() { return size; }

};

int main(){
    int n,k;
    cin>>n>>k;
    Queue text;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        text.push(s);
    }

    for(int i=0; i<k; i++){
        string temp = text.front();
        text.pop();
        text.push(temp);
    }

    while(!text.empty()){
        cout<<text.front()<<" ";
        text.pop();
    }
}
