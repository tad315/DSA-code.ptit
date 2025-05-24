#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, v, e;
vector<int> a[1005];
bool visited[1005];
int dis[1005], low[1005], p[1005];
bool isArt[1005];
int timer;

void reset(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        visited[i] = 0;
        dis[i] = low[i] = p[i] = 0;
        isArt[i] = 0;
    }
    timer = 0;
}

void dfs(int u)
{
    visited[u] = 1;
    dis[u] = low[u] = ++timer;
    int child = 0;
    for (int v : a[u])
    {
        if (!visited[v])
        {
            child++;
            p[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (p[u] == 0 && child > 1)
                isArt[u] = 1;
            if (p[u] != 0 && low[v] >= dis[u])
                isArt[u] = 1;
        }
        else if (v != p[u])
        {
            low[u] = min(low[u], dis[v]);
        }
    }
}


int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        reset(v);
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= v; ++i)
            if (!visited[i]) dfs(i);
        
        bool f = 0;
        for (int i = 1; i <= v; ++i)
        {
            if (isArt[i])
            {
                cout << i << " ";
                f = 1;
            }
        }
        if (!f) cout << "0";
        cout << endl;      
    }
    return 0;
}
