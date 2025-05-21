#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

vector<int> a[1005], revA[1005];
bool visited[1005];

void dfs(int u, vector<int> g[], bool visited[])
{
    visited[u] = 1;
    for (int v : g[u])
        if (!visited[v]) dfs(v, g, visited);
}

int main()
{
    boost;
    int t, v, e;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; ++i)
        {
            a[i].clear();
            revA[i].clear();
        }
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            revA[v].push_back(u);
        }
        memset(visited, 0, sizeof(visited));
        dfs(1, a, visited);
        bool check1 = 1;
        for (int i = 1; i <= v; ++i)
        {
            if (!visited[i]) check1 = 0;
        }

        memset(visited, 0, sizeof(visited));
        dfs(1, revA, visited);
        bool check2 = 1;
        for (int i = 1; i <= v; ++i)
        {
            if (!visited[i]) check2 = 0;
        }
        if (check1 && check2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
