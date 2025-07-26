#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll p = 10; p <= 1000000000LL; p *= 10)
        {
            if (n >= p) n = (n + p / 2) / p * p;
            else break;
        }
        cout << n << endl;
    }
    return 0;
}
