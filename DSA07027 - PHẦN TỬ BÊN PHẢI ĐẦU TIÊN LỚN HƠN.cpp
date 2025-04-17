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
        int a[n+1], res[n+1];
        for (int i = 0; i < n; ++i) cin >> a[i];
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && a[i] >= st.top()) st.pop();
            if (st.empty()) res[i] = -1;
            else res[i] = st.top();
            st.push(a[i]);
        }
        for (int i = 0; i < n; ++i) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
