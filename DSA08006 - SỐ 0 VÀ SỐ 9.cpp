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
        int n;
        cin >> n;

        queue<string> q;
        set<int> s;

        q.push("9");

        while (!q.empty())
        {
            string res = q.front();
            q.pop();

            int rem = 0;
            for (char c : res)
            {
                rem = (rem * 10 + (c - '0')) % n;
            }

            if (rem == 0)
            {
                cout << res << endl;
                break;
            }

            if (s.find(rem) == s.end())
            {
                s.insert(rem);
                q.push(res + "0");
                q.push(res + "9");
            }
        }
    }
    return 0;
}
