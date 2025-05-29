#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<pair<int, int>> dfs_tree;

void dfs(int u, int parent)
{
    visited[u] = 1;
    if (parent)
        dfs_tree.push_back({parent, u});
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M, u;
        cin >> N >> M >> u;

        for (int i = 1; i <= N; ++i)
        {
            adj[i].clear();
            visited[i] = false;
        }
        dfs_tree.clear();

        for (int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(u, 0);
    
        if (dfs_tree.size() == N - 1)
        {
            for (auto edge : dfs_tree)
            {
                cout << edge.first << " " << edge.second << "\n";
            }
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}
