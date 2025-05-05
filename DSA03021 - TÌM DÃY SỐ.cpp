#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    boost;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = INT_MAX;
    for (int first = 1; first <= a[0]; ++first)
    {
        int sum = first;
        int last = first;
        bool ok = true;

        for (int i = 1; i < n; ++i)
        {
            int val = a[i - 1] / last;

            int tmp = a[i] / (val + 1) + 1;
            if (tmp > a[i])
            {
                ok = false;
                break;
            }
            if (a[i] / tmp != val)
            {
                tmp = a[i] / val;
                if (tmp == 0 || a[i] / tmp != val)
                {
                    ok = false;
                    break;
                }
            }
            sum += tmp;
            last = tmp;
        }
        if (ok) ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
