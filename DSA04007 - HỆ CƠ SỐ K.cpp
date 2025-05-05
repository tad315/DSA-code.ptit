#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

ll toDec(string& s, int k) {
    ll res = 0;
    for (char c : s) res = res * k + (c - '0');
    return res;
}

string toBase(ll n, int k) {
    if (n == 0) return "0";
    string res;
    while (n) {
        res.push_back((n % k) + '0');
        n /= k;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    boost;
    int t, k;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> k >> a >> b;
        cout << toBase(toDec(a, k) + toDec(b, k), k) << endl;
    }
    return 0;
}
