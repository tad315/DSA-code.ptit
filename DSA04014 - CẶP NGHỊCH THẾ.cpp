#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int MAX = 1e6 + 5;
ll a[MAX], tmp[MAX];

ll solve(int l, int r)
{
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    ll ans = solve(l, mid) + solve(mid + 1, r);

    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else 
        {
            tmp[k++] = a[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int b = l; b <= r; ++b) a[b] = tmp[b];
    return ans; 
}

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(0, n - 1) << endl;
    }
    return 0;
}
