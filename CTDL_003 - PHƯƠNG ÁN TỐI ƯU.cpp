#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

vector<pair<int, int>> x;
vector<vector<int>> f;
string res;

void trace(int n, int v)
{
    if (n == 0)
        return;
    if (f[n][v] == f[n - 1][v])
        trace(n - 1, v);
    else
    {
        trace(n - 1, v - x[n].first);
        res[n - 1] = '1';
    }
}

int main()
{
    fast;

    int v, n;
    cin >> n >> v;

    f.assign(n + 1, vector<int>(v + 1, 0));
    x.assign(n + 1, {0, 0});
    res = string(n, '0');

    for (int i = 1; i <= n; ++i)
        cin >> x[i].second;

    for (int i = 1; i <= n; ++i)
        cin >> x[i].first;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            if (j < x[i].first)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - x[i].first] + x[i].second);
        }
    }

    cout << f[n][v] << endl;

    trace(n, v);

    for (char c : res)
        cout << c << ' ';
    cout << endl;

    return 0;
}
