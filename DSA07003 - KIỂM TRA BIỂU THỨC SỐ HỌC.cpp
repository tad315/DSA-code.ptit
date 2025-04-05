#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'

bool solve(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c != ')') st.push(c);
        else
        {
            bool check = 0;
            int cnt = 0;
            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') check = 1;
                else if (top != ' ') cnt++;
            }
            if (st.empty()) return 1;
            st.pop();
            if (!check && cnt <= 1) return 1;
        }
    }
    while (!st.empty())
    {
        if (st.top() == '(') return 1;
        st.pop();
    }
    return 0;
}

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
        if (solve(s)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
