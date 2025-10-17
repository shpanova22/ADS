#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main(){
    deque<int> boris;
    deque<int> nursik;
    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        boris.push_back(x);
    }
    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        nursik.push_back(x);
    }
    int moves=0;
    int maxmoves=pow(10,6);
    
    while(!boris.empty() && !nursik.empty() && moves<maxmoves){
        int b=boris.front();
        boris.pop_front();
        int n=nursik.front();
        nursik.pop_front();

        bool boriswins;
        if(b==0 && n==9 ){
            boriswins=true;
        } else if(b==9 && n==0){
            boriswins=false;
        } else {
            boriswins= b>n;
        }

        if(boriswins){
            boris.push_back(b);
            boris.push_back(n);
        } else {
            nursik.push_back(b);
            nursik.push_back(n);
        }
        moves++;



    }
    if(moves>=maxmoves){
        cout<<"blin nichya";
    } else if (boris.empty()){
        cout<<"Nursik"<<" "<< moves;
    } else {
        cout<<"Boris"<<" "<< moves;
    }
    return 0;
}