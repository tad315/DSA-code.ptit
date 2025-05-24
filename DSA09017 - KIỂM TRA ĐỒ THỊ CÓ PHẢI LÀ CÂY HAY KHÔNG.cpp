#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

vector<int> a[1005];
bool visited[1005];
bool check;

void reset(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        visited[i] = 0;
    }
}

void dfs(int u, int parent)
{
    visited[u] = true;
    for (int v : a[u])
    {
        if (!visited[v])
            dfs(v, u);
        else if (v != parent)
            check = 1;
    }
}

bool isTree(int n)
{
    dfs(1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            return 0;
    }
    return !check;
}

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        reset(n);
        check = 0;
        int u, v;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if (isTree(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
