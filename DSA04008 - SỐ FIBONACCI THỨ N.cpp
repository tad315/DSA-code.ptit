#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
const ll MOD = 1e9 + 7;

struct Matrix
{
    ll f[2][2];

    Matrix() 
    {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                this -> f[i][j] = 0;
    } 

    Matrix operator * (Matrix &b)
    {
        Matrix res;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    res.f[i][j] = (res.f[i][j] + this -> f[i][k] * b.f[k][j] % MOD) % MOD;
        return res;
    }
};

Matrix powMod(Matrix a, ll n)
{
    if(n == 1) return a;
    Matrix res = powMod(a, n / 2);
    res = res * res;
    if(n & 1) res = res * a;
    return res;
}

ll fibo(ll n)
{
    if(n == 0) return 0;
    Matrix f;
    f.f[0][0] = 1;
    f.f[0][1] = 1;
    f.f[1][0] = 1;
    f.f[1][1] = 0;
    Matrix res = powMod(f, n - 1);
    return res.f[0][0];
}

int main()
{
    fast;
    int t;
    cin >> t;
    ll n;
    while (t--)
    {
        cin >> n;
        Matrix a;
        a.f[0][0] = 1;
        a.f[0][1] = 1;
        a.f[1][0] = 1;
        a.f[1][1] = 0;
        Matrix res = powMod(a, n - 1);
        cout << fibo(n) << endl;
    }
    return 0;
}
