#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int maxBitonicSum(vector<int> &a)
{
    int n = a.size();
    vector<int> inc(n), dec(n);
    for (int i = 0; i < n; ++i)
    {
        inc[i] = a[i];
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])
                inc[i] = max(inc[i], inc[j] + a[i]);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        dec[i] = a[i];
        for (int j = n - 1; j > i; --j)
            if (a[j] < a[i])
                dec[i] = max(dec[i], dec[j] + a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, inc[i] + dec[i] - a[i]);

    return res;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        cout << maxBitonicSum(a) << '\n';
    }
    return 0;
}
