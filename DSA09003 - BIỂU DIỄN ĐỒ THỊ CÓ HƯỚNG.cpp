#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> adj(v + 1);
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= v; ++i)
        {
            sort(adj[i].begin(), adj[i].end());
            cout << i << ":";
            for (auto x : adj[i]) cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}
