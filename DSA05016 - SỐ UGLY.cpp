#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

vector<ll> u;

void pre(int n)
{
    u.resize(n + 1);
    u[0] = 1;
    int a = 0, b = 0, c = 0;
    ll x = 2, y = 3, z = 5;

    for (int i = 1; i <= n; ++i)
    {
        ll val = min({x, y, z});
        u[i] = val;
        if (val == x) x = u[++a] * 2;
        if (val == y) y = u[++b] * 3;
        if (val == z) z = u[++c] * 5;
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    vector<int> q(t), r;
    int m = 0;
    for (int &i : q)
    {
        cin >> i;
        m = max(m, i);
    }
    pre(m);
    for (int i : q) cout << u[i - 1] << '\n';
    return 0;
}
