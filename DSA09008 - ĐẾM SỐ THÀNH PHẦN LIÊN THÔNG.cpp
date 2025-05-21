#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

vector<int> a[1005];
bool visited[1005];

void dfs(int u)
{
    visited[u] = 1;
    for (int v : a[u])
        if (!visited[v]) dfs(v);
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
            visited[i] = 0;
        }
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int comp = 0;
        for (int i = 1; i <= v; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
                ++comp;
            }
        }
        cout << comp << endl;
    }
}
