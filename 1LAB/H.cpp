#include <iostream>

using namespace std;


int main(){
    int n;
    cin>>n;

    if (n<=1){
        cout<<"NO";
        return 0;
}

    bool isPrime=true;
    for(int i=2; i*i<=n; i++){
        if (n%i==0){
        isPrime=false;
        break;
    }
}
    if (isPrime) cout<<"YES";
    else cout<<"NO";

    return 0;
}
