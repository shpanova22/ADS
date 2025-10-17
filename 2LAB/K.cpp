#include <iostream>
#include <string>

using namespace std;

struct Node{
    char val;
    Node* next;
    Node(char a){
        val=a;
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
    void push(char a){
        Node* n = new Node(a);
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
        Node* old = head;
        head=head->next;
        delete old;
        size --;
        if(head==nullptr) tail=nullptr;
}

    char front(){
        if(empty()){
            return -1;
    }
        return head->val;
}

    bool empty() {return size==0;}
    int sz(){
        return size;
    }
};
int main(){
    int n;
    cin>>n;
    cin.ignore();

    for(int t=0; t<n; t++){
        int k;
        cin>>k;
        cin.ignore();

        string s;
        getline(cin, s);
    
        Queue arr;
        int count[26]={0};

        for(char ch : s){
            if(ch==' ') continue;

            count[ch-'a']++;
            arr.push(ch);

            while(!arr.empty() && count[arr.front()-'a']>1){
                arr.pop();
            }
            if(arr.empty()){
                cout<<-1<<" ";
            }
            else{
                cout<<arr.front()<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}
