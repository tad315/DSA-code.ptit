#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define MOD 1000000007
#define MAX 1001

ll fact[MAX];

ll power(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void preprocess()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
}

ll P(int n, int k)
{
    if (k > n)
        return 0;
    ll numerator = fact[n];
    ll denominator = fact[n - k];
    return numerator * power(denominator, MOD - 2) % MOD;
}

int main()
{
    boost;    
    int T;
    cin >> T;
    preprocess();
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        cout << P(n, k) << '\n';
    }
    return 0;
}
