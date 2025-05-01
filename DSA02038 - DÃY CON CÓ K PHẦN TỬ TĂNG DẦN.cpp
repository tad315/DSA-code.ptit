#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k, a[20], x[20];
void Try(int i, int pos)
{
    if (i > k)
    {
        for (int j = 1; j <= k; ++j) cout << x[j] << " ";
        cout << endl;
        return;
    }
    for (int j = pos; j <= n; ++j)
    {
        x[i] = a[j];
        Try(i + 1, j + 1);
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        Try(1, 1);
    }
    return 0;
}
