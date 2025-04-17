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
        string s;
        cin >> s;
        stack<int> st;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (isdigit(c)) st.push(c - '0');
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                int res; 
                switch (c)
                {
                    case '+': res = op1 + op2; break;
                    case '-': res = op1 - op2; break;
                    case '*': res = op1 * op2; break;
                    case '/': res = op1 / op2; break;
                }
                st.push(res);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
