#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()

vector<map<int, int>> dp;
bool check(int m, int x, int y)
{
    auto it = dp[m].lower_bound(x);
    if (it == dp[m].begin()) return 0;
    --it;
    return (*it).second < y;
}

void add(int l, int x, int y)
{
    auto it = dp[l].lower_bound(x);
    auto it2 = it;
    while (it != dp[l].end() && (*it).second >= y) ++it;
    dp[l].erase(it2, it);
    dp[l].insert({x, y});
}

int main()
{
    boost;
    int n, x, y, l, r, m;
    int ans = 0;

    cin >> n;
    dp.resize(n);
    add(0, -1e9, -1e9);
    while (n--)
    {
        cin >> x >> y;
        l = 0, r = ans;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (check(m, x, y)) l = m + 1;
            else r = m - 1;
        }
        if (ans == l - 1) ans = l;
        add(l, x, y);
    }
    cout << ans;
    return 0;
}
