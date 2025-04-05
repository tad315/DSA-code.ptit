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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        bool check = 0;
        for (int i = 0; i < n - 2 && !check; i++)
        {
            int tmp = k - a[i];
            int l = i + 1, r = n - 1;
            while (l < r && !check)
            {
                int sum = a[l] + a[r];
                if (sum == tmp)
                    check = 1;
                else if (sum < tmp)
                    l++;
                else
                    r--;
            }
        }
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
