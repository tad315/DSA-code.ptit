#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, s, d;
    cin >> t;
    while (t--)
    {
        cin >> s >> d;
        if (s > 9 * d || s == 0) 
        {
            cout << -1 << endl;
            continue;
        }
        string ans = "";
        for (int i = 0; i < d; i++) 
        {
            int x;
            if (i == 0) x = max(1, s - 9 * (d - i - 1));
            else x = max(0, s - 9 * (d - i - 1));
            if (x > 9) x = 9;
            ans += char(x + '0');
            s -= x;
        }
        cout << ans << endl;
    }
    return 0;
}
