#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int solve(vector<int> &a)
{
    int n = a.size();
    vector<int> inc(n, 1); 
    vector<int> dec(n, 1); 

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1]) inc[i] = inc[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; --i)
    {
        if (a[i] > a[i + 1]) dec[i] = dec[i + 1] + 1;
    }

    int maxLen = 1;
    for (int i = 0; i < n; ++i)
    {
        maxLen = max(maxLen, inc[i] + dec[i] - 1);
    }

    return maxLen;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(a) << endl;
    }
    return 0;
}
