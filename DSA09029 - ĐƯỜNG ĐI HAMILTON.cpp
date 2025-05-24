#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, v, e;
vector<int> a[15];
bool visited[15];
bool f;

void reset()
{
    for (int i = 1; i <= v; ++i)
    {
        a[i].clear();
    }
}

void dfs(int u, int cnt)
{
    if (cnt == v)
    {
        f = 1;
        return;
    }
    for (int v : a[u])
    {
        if (!visited[v])
        {
            visited[v] = 1;
            dfs(v, cnt + 1);
            visited[v] = 0;
        }
    }
}

bool checkHam()
{
    for (int i = 1; i <= v; ++i)
    {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        f = 0;
        dfs(i, 1);
        if (f) return 1;
    }
    return 0;
}

int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        reset();
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if (checkHam()) cout << "1";
        else cout << "0";
        cout << endl;
    }
}
