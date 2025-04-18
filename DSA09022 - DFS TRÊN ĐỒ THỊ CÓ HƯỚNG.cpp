#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int v, e, start;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u)
{
    cout << u << " ";
    visited[u] = 1;
    for (int v : adj[u])
        if (!visited[v]) dfs(v);
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 1001; i++)
            adj[i].clear();
        memset(visited, 0, sizeof(visited));
        cin >> v >> e >> start;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= v; i++)
            sort(adj[i].begin(), adj[i].end());
        dfs(start);
        cout << endl;
    }
    return 0;
}
