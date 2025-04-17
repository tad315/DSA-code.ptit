#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main() {
    fast;
    int Q;
    cin >> Q;
    deque<int> dq;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "PUSHFRONT") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (cmd == "PUSHBACK") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (cmd == "POPFRONT") {
            if (!dq.empty()) dq.pop_front();
        }
        else if (cmd == "POPBACK") {
            if (!dq.empty()) dq.pop_back();
        }
        else if (cmd == "PRINTFRONT") {
            if (dq.empty()) cout << "NONE\n";
            else cout << dq.front() << '\n';
        }
        else if (cmd == "PRINTBACK") {
            if (dq.empty()) cout << "NONE\n";
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}
