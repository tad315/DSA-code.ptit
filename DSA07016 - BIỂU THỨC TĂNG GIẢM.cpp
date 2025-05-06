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
    string s;
    while (t--)
    {
        cin >> s;
        stack<int> st;
        int n = 1;
        string res = "";

        for (int i = 0; i <= s.length(); ++i)
        {
            st.push(n++);
            if (i == s.length() || s[i] == 'I') {
                while (!st.empty()) {
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
