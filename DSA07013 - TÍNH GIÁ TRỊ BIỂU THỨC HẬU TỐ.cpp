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
        
        for (char c : s)
        {
            if (isdigit(c))
                st.push(c - '0');
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                if (st.size() < 2) continue;
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                
                switch (c)
                {
                    case '+': st.push(op1 + op2); break;
                    case '-': st.push(op1 - op2); break;
                    case '*': st.push(op1 * op2); break;
                    case '/': st.push(op1 / op2); break;
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
