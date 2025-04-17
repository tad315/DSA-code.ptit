#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        queue<int> q;
        while (n--) {
            int x;
            cin >> x;

            if (x == 1) {
                cout << q.size() << endl;
            }
            else if (x == 2) {
                if (q.empty()) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else if (x == 3) {
                int x;
                cin >> x;
                q.push(x);
            }
            else if (x == 4) {
                if (!q.empty()) q.pop();
            }
            else if (x == 5) {
                if (q.empty()) cout << -1 << endl;
                else cout << q.front() << endl;
            }
            else if (x == 6) {
                if (q.empty()) cout << -1 << endl;
                else cout << q.back() << endl;
            }
        }
    }
    return 0;
}
