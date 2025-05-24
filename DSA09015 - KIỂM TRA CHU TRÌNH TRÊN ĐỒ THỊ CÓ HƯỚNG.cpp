#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, v, e;
vector<int> a[1005];
bool visited[1005], inStack[1005];
bool check;

void reset(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        a[i].clear();
        visited[i] = inStack[i] = 0; 
    }
}

void dfs(int u)
{
    visited[u] = inStack[u] = 1;
    for (int v: a[u])
    {
        if (!visited[v]) dfs(v);
        else if (inStack[v]) check = 1;
    }
    inStack[u] = 0;
}


int main()
{
    boost;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        reset(v);
        check = 0;
        for (int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        for (int i = 1; i <= v; ++i)
        {
            if (!visited[i]) dfs(i);
        }  
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
