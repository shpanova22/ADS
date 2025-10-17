#include <iostream>
#include <deque>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int a=0; a<t; a++) {
        int n;
        cin >> n;
        deque<int> dq;

        for (int i = n; i >= 1; i--) {
            dq.push_front(i);
            for (int j = 0; j < i; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }

    cout<<endl;
    }
    return 0;
}

    