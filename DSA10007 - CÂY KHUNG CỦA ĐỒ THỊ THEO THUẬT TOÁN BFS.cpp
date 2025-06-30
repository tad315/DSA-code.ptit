#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MAX = 1005;
vector<int> a[MAX];
bool vis[MAX];
vector<pair<int, int>> tree;

void bfs (int start, int n)
{
    queue<int> q;
    vis[start] = 1;
    if (n) tree.pb({0, start});
    q.push(start);
    while (!q.empty())
    {
        int u = q.front(); 
        q.pop();
        for (int v : a[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                tree.pb({u, v});
                q.push(v);
            }
        }
    }
}
int main() {
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u;
        cin >> n >> m >> u;
        for (int i = 1; i <= n; ++i) a[i].clear();
        memset(vis, 0, sizeof(vis));
        tree.clear();
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        bfs(u, 0);
        if (tree.size() != n - 1) cout << -1 << endl;
        else 
        {
            for (auto &[x, y] : tree) cout << x << " " << y << endl;
        }
    }
    return 0;
}
