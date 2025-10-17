#include <iostream>
#include <deque>

using namespace std;

bool isPrime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
        return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    deque<int> primes;
    int num=2;

    while (primes.size()<=2000){
        if(isPrime(num)){
            primes.push_back(num);

        }
        num++;
    }

    deque<int> superprimes;
    for (int i=0; i<primes.size(); i++){
        if(isPrime(i+1)){
            superprimes.push_back(primes[i]);
        }
    }
    cout<<superprimes[n-1]<<endl;

    return 0;

}
