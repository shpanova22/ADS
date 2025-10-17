
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

class Stack{
private:
    int size;
    Node* top;

public:
    Stack(){
        size = 0;
        top=nullptr;
    }
    ~Stack(){
        while(!empty()){
            pop();
        }
    }

    void push(string s){
        Node* n = new Node(s);
            n->next = top;
            top = n;
        
        size++;
    }

    void pop(){
        if(empty()){
            cout<<"Empty";
            return;
        }
        Node* old = top;
        top= top->next;
       
        delete old;
        size--;
    }

    string topp(){
        if(empty()){
            return "   ";
        }
        return top->data;
    }

    bool empty(){ return size==0; }

    int sz() { return size; }

};

int main(){
    int n;
    cin>>n;
    
    Stack names;
    string prev="";


    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(i==0 || s!=prev){
            names.push(s);
        }
        prev=s;

    }
    cout<<"All in all:"<<" "<<names.sz()<<endl;
    cout<<"Students:"<<endl;
    while(!names.empty()){
        cout<<names.topp()<<endl;
        names.pop();
    }
    return 0;
}

   