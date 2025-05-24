#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, v, e, m;
vector<int> a[15];
int color[15];

void reset()
{
    for (int i = 1; i <= v; ++i)
    {
        a[i].clear();
        color[i] = 0; 
    }
}

bool isSafe (int n, int c)
{
    for (int x : a[n])
        if (color[x] == c) return 0;
    return 1;
}

bool solve(int n)
{
    if (n > v) return 1;
    for (int c = 1; c <= m; ++c)
    {
        if (isSafe(n, c))
        {
            color[n] = c;
            if (solve(n + 1)) return 1;
            color[n] = 0;
        }
    }
    return 0;
}

int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> v >> e >> m;
        reset();
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if (solve(1)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
