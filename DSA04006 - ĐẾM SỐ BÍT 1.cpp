#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

ll a[55];

void precompute() {
    a[1] = 1;
    for (int idx = 2; idx < 55; ++idx) {
        a[idx] = (a[idx - 1] << 1) + 1;
    }
}

inline int find(int idx, ll n, ll i) {
    while (idx > 1) {
        ll tmp = a[idx - 1];
        if (i == tmp + 1) return n & 1;
        if (i < tmp + 1) {
            --idx;
            n >>= 1;
        } else {
            --idx;
            n >>= 1;
            i -= tmp + 1;
        }
    }
    return n & 1;
}

int main() {
    boost;
    precompute(); 
    int t;
    ll n, l, r;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        int idx = 1;
        ll tmp = n;
        while (tmp >>= 1) ++idx; 
        ll ans = 0;
        for (ll i = l; i <= r; ++i) {
            ans += find(idx, n, i);
        }
        cout << ans << endl;
    }
    return 0;
}
