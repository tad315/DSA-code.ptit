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
const int MAX = 1e4 + 5;
ll a[MAX], b[MAX];
vector<int> dp(MAX);

int main()
{
    boost;
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int res[n];
    int g = n / k, idx = 0;
    for (int c = 0; c < k; ++c)
    {
        for (int r = 0; r < g; ++r)
        {
            res[r * k + c] = a[idx++];
        }
    }
    ll sum = 0;
    for (int i = 0; i < n - k; ++i)
    {
        sum += abs(res[i] - res[i + k]);
    }
    cout << sum;
    return 0;
}
