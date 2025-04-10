#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k, res;
int a[20];

void backTrack(int i, int gr, int s, int tmp)
{
    if (gr == k)
    {
        if (i == n)
            res++;
        return;
    }

    if (i == n)
        return;

    tmp += a[i];

    if (tmp == s)
        backTrack(i + 1, gr + 1, s, 0);

    backTrack(i + 1, gr, s, tmp);
}

int main()
{
    fast;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    res = 0;
    if (k <= n && (k == 1 || sum % k == 0))
    {
        int s = (k == 1) ? sum : sum / k;
        backTrack(0, 0, s, 0);
    }
    cout << res << endl;

    return 0;
}
