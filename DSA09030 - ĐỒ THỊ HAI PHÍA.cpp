#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, n, m;
vector<int> a[1005];
bool visited[1005];
int color[1005];

void reset()
{
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        visited[i] = 0;
        color[i] = -1;
    }
}

bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    visited[start] = 1;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : a[u])
        {
            if (!visited[v])
            {
                color[v] = 1 - color[u];
                visited[v] = 1;
                q.push(v);
            }
            else if (color[v] == color[u]) return 0;
        }
    }
    return 1;
}

bool solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i]) if(!bfs(i)) return 0;
    }
    return 1;
}
int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
