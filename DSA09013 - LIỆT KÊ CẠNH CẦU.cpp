#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int MAX = 1005;
vector<int> adj[MAX];
bool visited[MAX];
int disc[MAX], low[MAX], timer;
vector<pair<int, int>> bridges;

void dfs(int u, int p)
{
    visited[u] = 1;
    disc[u] = low[u] = ++timer;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (!visited[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                bridges.push_back({min(u, v), max(u, v)});
        }
        else
            low[u] = min(low[u], disc[v]);
    }
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= v; ++i)
        {
            adj[i].clear();
            visited[i] = 0;
            disc[i] = low[i] = 0;
        }
        bridges.clear();
        timer = 0;
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= v; ++i)
            if (!visited[i])
                dfs(i, -1);
        sort(bridges.begin(), bridges.end());
        for (const auto& bridge : bridges)
            cout << bridge.first << " " << bridge.second << " ";
        cout << endl;
    }
    return 0;
}
