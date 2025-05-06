#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int opt(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void solve(string s)
{
    stack<char> st;
    string res = "";

    for (char c : s)
    {
        if (isalpha(c)) res += c;
        else if (c == '(') st.push(c);
        else if (c == ')') 
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();                
        }
        else
        {
            while (!st.empty() && opt(st.top()) >= opt(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top(); st.pop();
    }
    cout << res << endl;
}

int main()
{
    boost;
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        solve(s);
    }
    return 0;
}
