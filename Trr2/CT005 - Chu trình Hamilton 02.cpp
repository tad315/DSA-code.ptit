#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int n, m, st;
set<int> se[1005];
int x[1005];
bool used[1005];
vector<vector<int>> tmp;
void hamliton(int u)
{
    for (int y : se[x[u - 1]])
    {
        if (u == n + 1 && y == st)
        {
            vector<int> cnt(x + 1, x + n + 1);
            cnt.push_back(st);
            tmp.push_back(cnt);
        }
        else if (!used[y])
        {
            x[u] = y;
            used[y] = true;
            hamliton(u + 1);
            used[y] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> st;
    // freopen("CT.in", "r", stdin);
    // freopen("CT.out", "w", stdout);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        se[x].insert(y);
        se[y].insert(x);
    }
    x[1] = st;
    used[x[1]] = true;
    hamliton(2);
    if (tmp.size() != 0)
    {
        cout << tmp.size() << endl;
        for (auto it : tmp)
        {
            for (int x : it)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << tmp.size();
    }
}
