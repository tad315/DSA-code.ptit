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

ll len[46], res[46];

ll cntA (int n, ll k)
{
    if (n == 0) 
    {
        if (k >= 1) return 1;
        else return 0;
    }
    if (n == 1) return 0;
    if (k >= len[n]) return res[n];
    if (k <= len[n - 1]) return cntA(n - 1, k);
    return res[n - 1] + cntA(n - 2, k - len [n - 1]);
}
int main()
{
    boost;
    len[0] = 1; len[1] = 1;
    res[0] = 1; res[1] = 0;
    for (int i = 2; i < 46; ++i) 
    {
        len[i] = len[i - 1] + len[i - 2];
        res[i] = res[i - 1] + res[i - 2];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        cout << cntA(n, k) << endl;
    }
    return 0;
}
