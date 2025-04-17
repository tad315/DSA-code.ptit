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
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') st.push(i);
            else 
            {
                st.pop();
                if (!st.empty())
                {
                    ans = max(ans, i - st.top());
                }
                else st.push(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
