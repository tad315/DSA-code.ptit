#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int t, n, a[20];
vector<vector<int>> res;

void solve()
{
    res.clear();
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        vector<int> tmp;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask >> i & 1)
            {
                tmp.push_back(a[i]);
                sum += a[i];
            }
        }
        if (sum & 1) res.push_back(tmp);
    }

    sort(res.begin(), res.end());
    for (auto &v : res)
    {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
}
int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n, greater<int>());
        solve();
    }
    return 0;
}
