#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        ll a[x], b[y], c[z];
        for (int i = 0; i < x; i++)
            cin >> a[i];
        for (int i = 0; i < y; i++)
            cin >> b[i];
        for (int i = 0; i < z; i++)
            cin >> c[i];

        int indA, indB, indC;
        indA = indB = indC = 0;
        multiset<ll> ans;
        while (indA < x && indB < y && indC < z)
        {
            if (a[indA] == b[indB] && b[indB] == c[indC])
            {
                ans.insert(a[indA]);
                indA++;
                indB++;
                indC++;
            }
            else if (a[indA] < b[indB]) indA++;
            else if (b[indB] < c[indC]) indB++;
            else indC++;
        }
        if (ans.size() == 0) cout << -1 << endl;
        else
        {
            for (auto it : ans) cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}
