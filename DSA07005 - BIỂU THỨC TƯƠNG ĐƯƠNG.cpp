#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

string solve(string &s)
{
    stack<bool> st;
    st.push(1);

    string res;
    bool sign = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        char ch = s[i];
        if (ch == '+') sign = 1;
        else if (ch == '-') sign = false;
        else if (ch == '(')
        {
            if (sign) st.push(st.top());
            else st.push(!st.top());
            sign = 1;
        }
        else if (ch == ')') st.pop();
        else if (isalpha(ch))
        {
            bool currentSign = (sign == st.top());
            if (!res.empty()) res += currentSign ? '+' : '-';
            else res += currentSign ? "" : "-";
            res += ch;
            sign = 1;
        }
    }
    return res;
}

int main()
{
    boost;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        cout << solve(s) << endl;
    }
    return 0;
}
