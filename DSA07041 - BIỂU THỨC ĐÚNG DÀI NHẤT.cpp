#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int open = 0, res = 0;
        for (char c : s)
        {
            if (c == '(') ++open;
            else 
            {
                if (open > 0)
                {
                    --open;
                    res += 2;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
