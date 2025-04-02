#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int n, k, a[1005];

void prev_combination() {
    int i = k - 1;
    while (i >= 0 && a[i] == a[i - 1] + 1) {
        i--;
    }
    if (i == -1) {
        for (int j = 0; j < k; j++) {
            cout << n - k + j + 1 << " ";
        }
    } else {
        a[i]--;
        for (int j = i + 1; j < k; j++) {
            a[j] = n - k + j + 1;
        }
        for (int j = 0; j < k; j++) {
            cout << a[j] << " ";
        }
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        prev_combination();
        if (t>=1) cout << '\n';
    }
    return 0;
}
