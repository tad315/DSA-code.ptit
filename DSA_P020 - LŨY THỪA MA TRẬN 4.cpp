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
const int mod = 1e9 + 7;

struct Matrix
{
    int n;
    vector<vector<ll>> a;

    Matrix(int n) : n(n), a(n, vector<ll>(n)) {}

    Matrix operator*(Matrix &b)
    {
        Matrix res(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    res.a[i][j] = (res.a[i][j] + this->a[i][k] * b.a[k][j] % mod) % mod;
        return res;
    }

    Matrix pow(ll k)
    {
        Matrix res(n);
        for (int i = 0; i < n; ++i)
            res.a[i][i] = 1;
        Matrix tmp = *this;
        while (k)
        {
            if (k & 1)
                res = res * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return res;
    }
};

int main()
{
    boost;
    int t, n;
    ll k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Matrix A(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A.a[i][j];
        Matrix res = A.pow(k);
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += res.a[0][i];
        }
        cout << sum % mod << endl;
    }
    return 0;
}
