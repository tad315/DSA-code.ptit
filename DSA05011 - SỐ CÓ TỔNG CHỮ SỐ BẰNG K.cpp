#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int mod = 1e9 + 7;
const int MAXK = 50000;

int main()
{
    boost;
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> prev(k + 1, 0), cur(k + 1, 0);
        for (int i = 1; i <= 9 && i <= k; ++i)
            prev[i] = 1;

        for (int i = 2; i <= n; ++i)
        {
            fill(all(cur), 0);
            for (int sum = 0; sum <= k; ++sum)
                for (int d = 0; d <= 9; ++d)
                    if (sum >= d)
                        cur[sum] = (cur[sum] + prev[sum - d]) % mod;
            swap(prev, cur);
        }
        if (n == 1)
        {
            if (k >= 1 && k <= 9) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else cout << prev[k] << endl;
    }
    return 0;
}
