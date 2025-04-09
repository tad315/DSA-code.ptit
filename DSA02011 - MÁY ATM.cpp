#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k, res;
int a[35];

void backTrack(int i, int sum, int cnt)
{
    if (sum > k || cnt >= res)
        return;

    if (sum == k)
    {
        res = min(res, cnt);
        return;
    }

    for (int j = i; j < n; j++)
        backTrack(j + 1, sum + a[j], cnt + 1);
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        res = INT_MAX;
        backTrack(0, 0, 0);
        if (res == INT_MAX)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}
