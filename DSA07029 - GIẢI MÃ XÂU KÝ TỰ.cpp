#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

string solve(string s)
{
    stack<char> st;
    string n, tmp, a, ans;
    ans = "";
    for (char &i : s)
    {
        if (i == ']')
        {
            n = tmp = "";
            while (!st.empty() && st.top() != '[')
            {
                tmp += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
            while (!st.empty() && isdigit(st.top()))
            {
                n = st.top() + n;
                st.pop();
            }
            a = "";
            if (n == "") n = "1";
            int limit = stoi(n);
            for (int j = 1; j <= limit; ++j) a += tmp;
            for (int j = a.size() - 1; j >= 0; --j) st.push(a[j]);
        }
        else st.push(i);
    }
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
