#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

ll com(ll a, ll b, const string &op)
{
    switch (op[0])
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }  
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<ll> st;
        while (n--)
        {
            string s;
            cin >> s;
            if (s == "+" || s == "-" || s =="*" || s == "/")
            {
                ll b = st.top();
                st.pop();
                ll a = st.top();
                st.pop();
                ll c = com(a,b,s);
                st.push(c);
            }
            else
                st.push(stoll(s));
        }
        cout << st.top() << endl;
    }
    return 0;
}
