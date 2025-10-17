#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string ss;
    cin>>ss;
    stack<char> balanced;
    if(ss.size()%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    else {
        for(char ch : ss)
            if(balanced.empty() || ch!=balanced.top()){
                balanced.push(ch);
            }
            else{
                balanced.pop();
            }
    }
    if(balanced.empty()){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
    return 0;


}
