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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        long long ans = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int sum = a[l] + a[r];
            if (sum == k)
            {
                if (a[l] == a[r])
                {
                    long long cnt = r - l + 1;
                    ans += cnt * (cnt - 1) / 2;
                    break;
                }
                int cnt_l = 1, cnt_r = 1;
                while (l + 1 < r && a[l] == a[l + 1])
                {
                    cnt_l++;
                    l++;
                }
                while (r - 1 > l && a[r] == a[r - 1])
                {
                    cnt_r++;
                    r--;
                }
                ans += cnt_l * cnt_r;
                l++;
                r--;
            }
            else if (sum < k) l++;
            else r--;
        }
        cout << ans << endl;
    }
    return 0;
}
