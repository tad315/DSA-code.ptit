#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        vector<int> next(n, -1), ans(n, -1);

        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < n; ++i)
        {
            int j = next[i];
            if (j == -1) continue;

            for (int k = j + 1; k < n; ++k)
            {
                if (a[k] < a[j])
                {
                    ans[i] = a[k]; 
                    break;
                }
            }
        }
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}
