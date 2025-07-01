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
vector<int> a[MAX], cycle;
bool vis[MAX];
int parent[MAX];
bool f;

void dfs(int u, int p)
{
    if (f) return;
    vis[u] = 1;
    for (int v : a[u])
    {
        if (!vis[v])
        {
            parent[v] = u;
            dfs(v, u);
            if (f) return;
        }
        else if (v == 1 && v != p)
        {
            cycle.pb(1);
            int cur = u;
            while (cur != 1)
            {
                cycle.pb(cur);
                cur = parent[cur];
            }
            cycle.pb(1);
            reverse(all(cycle));
            f = 1;
            return;
        }
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) 
        {
            a[i].clear();
            vis[i] = 0;
            parent[i] = 0;
        }
        f = 0;
        cycle.clear();
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        for (int i = 1; i <= n; ++i) sort(all(a[i]));
        dfs(1, 0);
        if (!f) cout << "NO\n";
        else
        {
            for (int x : cycle) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
