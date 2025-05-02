#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, n;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n >> s;
        sort(s.begin(), s.end());
        int len = s.length();
        vector<string> res;

        for (int mask = 1; mask < (1 << len); ++mask)
        {
            string tmp = "";
            for (int i = 0; i < len; ++i)
                if (mask & (1 << i)) tmp += s[i];
            res.push_back(tmp);
        }
        sort(res.begin(), res.end());
        for (string x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
