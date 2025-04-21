#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int main(){
    fast;
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;

    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int v; cin >> v;
            if (v < 1 || v > n) {
                return 0;
            }
            adj[i].push_back(v);
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i)
            cout << adj[i].size() << ' ';
        cout << '\n';
    }
    else if (t == 2) {
        set<pair<int,int>> edges;
        for(int u = 1; u <= n; ++u)
            for(int v : adj[u])
                if (u < v)
                    edges.emplace(u, v);

        int m = edges.size();
        cout << n << ' ' << m << '\n';

        vector<pair<int,int>> E(edges.begin(), edges.end());
        vector<vector<int>> mat(n+1, vector<int>(m, 0));
        for (int j = 0; j < m; ++j) {
            auto [u, v] = E[j];
            mat[u][j] = mat[v][j] = 1;
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j)
                cout << mat[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
