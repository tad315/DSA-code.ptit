#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k, s, res;

void dfs (int pos, int cnt, int sum)
{
    if (cnt > k || sum > s) return; 
    if (cnt == k)
    {
        if (sum == s) ++ res;
        return;
    }
    for (int i = pos + 1; i <= n; ++i)
        dfs (i, cnt + 1, sum + i);
}

int main()
{
    boost;
    while (cin >> n >> k >> s, n || k || s)
    {
        res = 0;
        dfs (0, 0, 0);
        cout << res << endl;
    }
    return 0;
}
