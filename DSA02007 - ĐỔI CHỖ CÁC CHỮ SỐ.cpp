#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

string ans;
void solve(string s, int k)
{
    if (k == 0) {
        ans = max(ans, s);
        return;
    }
    int n = s.length();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (s[j] > s[i])
            {
                swap(s[i], s[j]);
                ans = max(ans, s);
                solve (s, k - 1);
                swap(s[i], s[j]);
            }
        }
    }

}

int main()
{
    boost;
    int t, k;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> k >> s;
        ans = s;
        solve(s, k);
        cout << ans << endl;
    }
    return 0;
}
