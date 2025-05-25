#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, n, m;
int p[1005];


int find(int u) {
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

bool unionSet(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return 0;
    p[pu] = pv;
    return 1;
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) p[i] = i;
        
        bool ok = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if (!unionSet(u, v)) ok = 1;
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
