#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, n, m;
int p[100005];
int sizeS[100005];

int find(int u)
{
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
    {
        p[rootV] = rootU;
        sizeS[rootU] += sizeS[rootV];
    }
}
int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;
            sizeS[i] = 1;
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            unionSet(u, v);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (p[i] == i)
                ans = max(ans, sizeS[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
