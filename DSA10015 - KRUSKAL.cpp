#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int v, e;
vector<int> p, s;

int find(int u)
{
    if (u == p[u]) return u;
    return find(p[u]);
}

bool unionSet(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x;
    s[x] += s[y];
    return 1;
}
bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) < get<2>(b);
}
int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        p.resize(v + 1);
        s.resize(v + 1, 1);
        for (int i = 1; i <= v; ++i) p[i] = i;
        vector<tuple<int, int, int>> adj;
        for (int i = 0; i < e; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj.emplace_back(u, v, w);
        }
        sort(adj.begin(), adj.end(), cmp);
        int ans = 0;
        for (auto &[u, v,w] : adj)
        {
            if (unionSet(u, v)) ans += w;
        }
        cout << ans << endl;
    }
}
