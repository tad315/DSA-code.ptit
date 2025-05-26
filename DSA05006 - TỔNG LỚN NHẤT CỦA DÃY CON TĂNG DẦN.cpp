#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int solve(vector<int> &a, int n)
{
    vector<int> dp(n);
    int res = 0;

    for (int i = 0; i < n; ++i)
    {
        dp[i] = a[i];
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        cout << solve(a, n) << endl;
    }
    return 0;
}
