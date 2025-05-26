#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

string normalize(const string &s)
{
    string res;
    stack<int> st;
    int sign = 1;
    st.push(sign);

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '+') continue;

        if (s[i] == '-')
        {
            if (i == 0 || s[i - 1] == '(') res += '-';
            else res += '+';
        }
        else if (s[i] == '(')
        {
            if (i > 0 && s[i - 1] == '-')
                st.push(st.top() * -1);
            else st.push(st.top());
        }
        else if (s[i] == ')') st.pop();
        else
        { 
            if (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')
            {
                if (st.top() == -1) res += '-';
            }
            res += s[i];
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
        string a, b;
        getline(cin, a);
        getline(cin, b);
        if (normalize(a) == normalize(b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
