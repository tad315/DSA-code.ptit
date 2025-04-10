#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k, res;
int a[35];
bool c;

void backTrack(int ind, int s, int cnt, int i)
{
    if (s == k)
    {
        if (cnt < res) res = cnt;
        return;
    }
    
    if (ind == n || s > k || cnt >= res) return;

    for (int j = i; j < n; j++)
    {
        if (s + a[j] <= k) backTrack(ind + 1, s + a[j], cnt + 1, j + 1);
    }
    
}
    

int main()
{
    fast;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    res = 1e9;
    backTrack(0, 0, 0, 0);
    if (res == 1e9) cout << -1;
    else cout << res;
    return 0;
}
