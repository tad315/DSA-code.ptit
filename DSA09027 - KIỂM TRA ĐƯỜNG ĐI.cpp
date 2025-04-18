#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int p[1005];

int find(int u)
{
    if (p[u] == u)
        return u;
    return p[u] = find(p[u]);
}

void Union(int u, int v)
{
    int pu = find(u);
    int pv = find(v);
    if (pu != pv)
        p[pu] = pv;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            p[i] = i;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }
        int q;
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
