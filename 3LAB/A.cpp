#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,t,x;
    int test[10005];

    map<int, pair<int, int>>mp; //first index of number, pair-pos
    

    cin>>t;
    for(int i=1;i<=t; i++) cin>>test[i];

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            cin>>x;
            mp[x]={i,j};
            
        }
    }
    for (int i=1; i<=t;i++){
        if(mp.count(test[i])) cout<<mp[test[i]].first<<' '<<mp[test[i]].second<<endl;
        else cout<< -1 <<endl;
    }

    return 0;

}
