#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int MAX = 1005;
vector<int> adj[MAX]; 
bool visited[MAX];    
int parent[MAX];      

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void tracePath(int s, int t)
{
    if (!visited[t])
    {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    while (t != s)
    {
        path.push_back(t);
        t = parent[t];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int V, E, s, t;
        cin >> V >> E >> s >> t;

        for (int i = 1; i <= V; ++i) adj[i].clear();
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));

        for (int i = 0; i < E; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(s);
        tracePath(s, t);
    }
    return 0;
}
