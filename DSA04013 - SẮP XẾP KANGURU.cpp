#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main() {
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        int i = 0, j = n / 2, pairs = 0;
        while (i < n / 2 && j < n)
        {
            if (a[j] >= 2 * a[i])
            {
                ++pairs;
                ++i;
            }
            ++j;
        }
        cout << n - pairs << endl;
    }
    return 0;
}
