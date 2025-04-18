#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int MAX = 1005;
vector<int> adj[MAX];
bool visited[MAX];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int v, e, start;
        cin >> v >> e >> start;
        for (int i = 1; i <= v; ++i)
        {
            adj[i].clear();
            visited[i] = 0;
        }
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= v; ++i)
            sort(adj[i].begin(), adj[i].end());
        bfs(start);
        cout << endl;
    }
    return 0;
}
