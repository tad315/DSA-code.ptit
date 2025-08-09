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
const ll mod = 1e9 + 7;
int main()
{
    boost;
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        int s1, s2, f1, f2;
        cin >> s1 >> s2 >> f1 >> f2;
        cout << max(abs(s1 - f1), abs(s2 - f2));
    }
    return 0;
}
