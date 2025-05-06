#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool isOpt(char c)
{
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '^';
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
        stack<string> st;
        for (char c : s)
        {
            if (isOpt(c))
            {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string tmp = "(" + op1 + c + op2 + ")";
                st.push(tmp);
            }
            else st.push(string(1, c));
        }
        cout << st.top() << endl;
    }
    return 0;
}
