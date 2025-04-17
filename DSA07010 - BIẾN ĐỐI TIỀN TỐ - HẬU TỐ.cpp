#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
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
        stack<string> st;

        for (int i = s.length() - 1; i >= 0; --i) 
        {
            char c = s[i];
            if (isOperator(c))
            {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string res =  op1 + op2 + c;
                st.push(res);
            }
            else st.push(string(1, c));
        }
        cout << st.top() << endl;
    }
    return 0;
}
