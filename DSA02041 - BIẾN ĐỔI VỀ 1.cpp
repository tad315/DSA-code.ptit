#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int dp[100005];

void pre()
{
    dp[1] = 0;
    for (int i = 2; i <= 100000; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
}

int main()
{
    boost;
    pre();
    int t;
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        cout << dp[n] << endl;
    }
}
