#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k, sum, target;
vector<int> a, s;

bool Try(int i)
{
    if (i == n)
    {
        for (int j = 0; j < k; ++j)
            if (s[j] != target) return 0;
        return 1;
    }

    for (int j = 0; j < k; ++j)
    {
        if (s[j] + a[i] <= target)
        {
            s[j] += a[i];
            if (Try(i + 1)) return 1;
            s[j] -= a[i];
        }
        if (s[j] == 0) break;
    }
    return 0;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a.resize(n);
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % k != 0)
        {
            cout << 0 << endl;
            continue;
        }
        target = sum / k;
        sort(a.rbegin(), a.rend());
        if (a[0] > target)
        {
            cout << 0 << endl;
            continue;
        }
        s.assign(k, 0); 
        if (Try(0)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
