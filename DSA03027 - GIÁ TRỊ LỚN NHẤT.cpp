#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int n;
    cin >> n;
    int a[n];
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        res += (a[i] > 0) * (a[i] << 1);
    }
    cout << res;
    return 0;
}
