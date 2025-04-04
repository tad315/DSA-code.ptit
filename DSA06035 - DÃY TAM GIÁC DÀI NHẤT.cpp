#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> up(n, 1), down(n, 1);
        up[0] = down[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
                up[i] = up[i - 1] + 1;
            else
                up[i] = 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
                down[i] = down[i + 1] + 1;
            else
                down[i] = 1;
        }

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, up[i] + down[i] - 1);
        }

        cout << ans << '\n';
    }
    return 0;
}
