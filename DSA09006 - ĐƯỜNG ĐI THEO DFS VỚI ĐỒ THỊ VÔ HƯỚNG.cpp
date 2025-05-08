#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int V, E, s, t;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void dfs(int u)
{
    visited[u] = 1;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            dfs(v);
        }
    }
}

void findPath(int s, int t)
{
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if (!visited[t])
    {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    while(t != s)
    {
        path.push_back(t);
        t = parent[t];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
    cout << endl;
}

int main()
{
    boost;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> V >> E >> s >> t;
        for (int i = 1; i <= V; ++i) adj[i].clear();
        for (int i = 0; i < E; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        findPath(s, t);
    }
    return 0;
}
