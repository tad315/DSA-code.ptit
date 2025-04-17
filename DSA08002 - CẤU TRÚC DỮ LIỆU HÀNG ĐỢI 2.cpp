#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main() {
    fast;
    int Q;
    cin >> Q;
    queue<int> q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        } else if (cmd == "POP") {
            if (!q.empty()) q.pop();
        } else if (cmd == "PRINTFRONT") {
            if (q.empty()) cout << "NONE\n";
            else cout << q.front() << '\n';
        }
    }

    return 0;
}
