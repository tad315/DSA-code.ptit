#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long dp[k + 1] = {0};
        dp[0] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int x : a)
            {
                if (i >= x) dp[i] = (dp[i] + dp[i - x]) % mod;
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
