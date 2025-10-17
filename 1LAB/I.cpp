#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n; 
    if (!(cin >> n)) return 0;
    string s; cin >> s;

    queue<int> QS, QK;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') QS.push(i);
        else QK.push(i);
    }

    while (!QS.empty() && !QK.empty()) {
        int iS = QS.front(); QS.pop();
        int iK = QK.front(); QK.pop();
        if (iS < iK) {
            QS.push(iS + n);
        } else {
            QK.push(iK + n);
        }
    }

    if (!QS.empty())
    { cout << "SAKAYANAGI";
    }
    else cout << "KATSURAGI";
    return 0;
}