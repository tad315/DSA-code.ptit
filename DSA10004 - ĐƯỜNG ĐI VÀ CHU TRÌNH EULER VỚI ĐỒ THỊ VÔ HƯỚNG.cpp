#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<int> deg(v + 1, 0);
        for (int i = 0; i < e; ++i)
        {
            int x, y;
            cin >> x >> y;
            ++deg[x];
            ++deg[y];
        }
        int odd = 0;
        for (int i = 1; i <= v; ++i)
        {
            if (deg[i] % 2 != 0) ++odd;
        }
        if (odd == 0)
            cout << 2 << endl;
        else if (odd == 2)
            cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
