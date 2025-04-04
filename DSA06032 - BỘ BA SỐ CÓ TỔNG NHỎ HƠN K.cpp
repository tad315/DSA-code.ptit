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
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                long long sum = a[i] + a[l] + a[r];
                if (sum < k)
                {
                    cnt += r - l;
                    l++;
                }
                else
                    r--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
