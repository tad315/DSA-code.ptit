#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s, tmp;
        cin >> s;
        stack<string> st;
        for (char c : s)
        {
            if (isalpha(c))
                st.push(string(1, c));
            else
            {
                tmp = st.top();
                st.pop();
                tmp = st.top() + tmp;
                st.pop();
                tmp = c + tmp;
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
