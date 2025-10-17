#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int a;
    cin>>a;

    int bestIndex=0;
    int minDist=abs(v[0]-a);

    for (int i=1; i<n; i++){
        int dist=abs(v[i]-a);
        if(dist<minDist){
            minDist=dist;
            bestIndex=i;
        }
    }
    cout<< bestIndex<< endl;
    return 0;
}
