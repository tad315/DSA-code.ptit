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
        if (n < 2)
        {
            cout << "NO\n";
            continue;
        }
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int ans = -1;
        int minInd = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                if (a[i - 1].second < minInd)
                {
                    minInd = a[i - 1].second;
                    ans = a[i].first;
                }
            }
        }
        if (ans != -1) cout << ans << '\n';
        else cout << "NO\n";
    }
    return 0;
}
