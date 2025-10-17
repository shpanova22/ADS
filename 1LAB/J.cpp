#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    string str;
    int x;

    while(cin>>str){
        if (str=="+"){
            cin>>x;
            dq.push_front(x);
        }
        else if (str=="-"){
            cin>>x;
            dq.push_back(x);
        }
        else if(str=="!"){
            continue;
        }
        else if(str=="*"){
            if(dq.empty()){
                cout<<"error"<< endl;
            }
            else if (dq.size()==1){
                cout<<dq.front()*2 << endl;
                dq.pop_front();
            }
            else {
                int sum=dq.front() + dq.back();
                cout <<sum<< endl;
                dq.pop_front();
                dq.pop_back();

            }
        
        }


             
    }
    return 0;

}