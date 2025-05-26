#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define MOD 1000000007

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<double> A(N), B(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i] >> B[i];

        vector<int> dp(N, 1); 
        int res = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (A[j] < A[i] && B[j] > B[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << '\n';
    }
    return 0;
}
