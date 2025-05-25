#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, n, m;
int p[100005];
int sizeS[100005];
unordered_map<int, int> eCnt;

int find(int u) {
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

void unionSet(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    if (ru != rv) {
        p[rv] = ru;
        sizeS[ru] += sizeS[rv];
        eCnt[ru] += eCnt[rv];
    }
}

int main() {
    boost;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            sizeS[i] = 1;
        }
        eCnt.clear();

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            unionSet(u, v);
            int r = find(u);
            eCnt[r]++;
        }

        bool ok = 1;
        for (int i = 1; i <= n && ok; ++i) {
            if (p[i] == i) {
                ll sz = sizeS[i];
                ll e = eCnt[i];
                if (e != sz * (sz - 1LL) / 2) {
                    ok = 0;
                }
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
