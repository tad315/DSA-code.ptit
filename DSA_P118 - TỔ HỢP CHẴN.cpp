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

void in()
{
    int sum = 0;
    for (int i = 1; i <= k; ++i) sum += a[i];
    if (sum % 2 == 0) 
    {
        for (int i = 1; i <= k; ++i) cout << a[i] << " ";
        cout << endl;
    }
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
