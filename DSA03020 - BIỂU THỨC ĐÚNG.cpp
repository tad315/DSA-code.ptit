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
        int l = 0, r = 0, ans = 0, cnt = 0;
        for (char c : s)
        {
            if (c == '[')
            {
                ++l;
                if (cnt > 0)
                {
                    ans += cnt;
                    --cnt;
                }
            }
            else 
            {
                ++r;
                cnt = r - l;
            }
        } 
        cout << ans << endl;
    }
    return 0;
}
