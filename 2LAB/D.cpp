#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    map<int, int> freq;
    int maxFreq=0;

    for(int x : a ){
        freq[x]++;
        maxFreq=max(maxFreq, freq[x]);
    }
        
    vector <int> modes;
    for(auto &p : freq){
        if(p.second==maxFreq){
            modes.push_back(p.first);
        }
    }
    sort(modes.rbegin(),modes.rend());
    for( int x : modes){
        cout<<x<< " ";
    }
    cout<<endl;

    return 0;
}
