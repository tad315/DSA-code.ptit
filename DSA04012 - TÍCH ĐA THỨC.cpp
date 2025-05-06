#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main() {
    boost;
    int t, m, n, p[105], q[105], r[205];
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 0; i < m; ++i) cin >> p[i];
        for (int i = 0; i < n; ++i) cin >> q[i];
        fill(r, r + m + n - 1, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                r[i + j] += p[i] * q[j];
        for (int i = 0; i < m + n - 1; ++i) 
            cout << r[i] << " ";
        cout << endl;
    }
    return 0;
}
