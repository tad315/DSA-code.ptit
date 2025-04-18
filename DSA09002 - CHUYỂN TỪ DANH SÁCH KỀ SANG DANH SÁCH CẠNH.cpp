#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        while (ss >> x)
            adj[i].push_back(x);
    }

    vector<pair<int, int>> e;
    for (int u = 1; u <= n; ++u)
    {
        for (int v : adj[u])
        {
            if (u < v)
                e.emplace_back(u, v);
        }
    }

    sort(e.begin(), e.end());
    for (auto [u, v] : e)
        cout << u << " " << v << endl;

    return 0;
}
