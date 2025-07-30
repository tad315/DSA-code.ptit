#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int n, k;
int a[15];
int cnt = 1;

bool snt(int x)
{
    if (x <= 1) return 0;
    if (x == 2) return 1;
    else if (x % 2 == 0) return 0;
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}

void in()
{
    if (snt(cnt))
    {
        cout << cnt << ": ";
        for (int i = 1; i <= k; ++i) cout << a[i] << " ";
        cout << endl;
    }
    cnt++;
}

void Try(int i, int s)
{
    if (i > k)
    {
        in();
        return;
    }
    for (int j = s; j <= n - k + i; ++j)
    {
        a[i] = j;
        Try(i + 1, j + 1);
    }
}
int main()
{
    boost;
    cin >> n >> k;
    Try(1, 1);
    return 0;
}
