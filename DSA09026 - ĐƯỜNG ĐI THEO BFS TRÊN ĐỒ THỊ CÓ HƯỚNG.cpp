#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int v, e, start, endN;
vector<int> adj[1001];
bool visited[1001];
int p[1001];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int v : adj[cur])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                p[v] = cur;
                q.push(v);
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
        for (int i = 0; i < 1001; i++)
            adj[i].clear();
        memset(visited, 0, sizeof(visited));
        memset(p, 0, sizeof(p));
        cin >> v >> e >> start >> endN;
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        bfs(start);
        if (!visited[endN])
            cout << -1 << endl;
        else
        {
            vector<int> path;
            for (int u = endN; u != start; u = p[u])
                path.push_back(u);
            path.push_back(start);
            reverse(path.begin(), path.end());
            for (int x : path)
                cout << x << " ";
            cout << endl;
        }
    }
}
