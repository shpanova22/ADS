#include <iostream>
#include <string>
#include <stack>

using namespace std;

string process(string s){
    stack <char> st;

    for (char c : s){
        if (c=='#'){
            if (!st.empty()){
                st.pop();
            }
        }else {
            st.push(c);
        }

    }
    string result=" ";
    while(!st.empty()){
        result=st.top()+ result;
        st.pop();
    }
    return result;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    if (process(s1)==process(s2)){
        cout<<"Yes"<<" ";
    } else{
        cout<<"No"<<" ";
    }
    return 0;
    
}