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
    cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);

        vector<string> v;
        stringstream ss(s);
        string token;
        while (ss >> token)
            v.push_back(token);

        stack<ll> st;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            string token = v[i];
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                ll op1 = st.top();
                st.pop();
                ll op2 = st.top();
                st.pop();
                if (token == "+")
                    st.push(op1 + op2);
                else if (token == "-")
                    st.push(op1 - op2);
                else if (token == "*")
                    st.push(op1 * op2);
                else if (token == "/")
                    st.push(op1 / op2);
            }
            else
                st.push(stoll(token));
        }
        cout << st.top() << endl;
    }
    return 0;
}
