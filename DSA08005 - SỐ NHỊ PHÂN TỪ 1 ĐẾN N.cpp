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
        int n;
        cin >> n;

        queue<string> q;
        vector<string> ans;

        q.push("1");
        while (ans.size() < n)
        {
            string s1 = q.front();
            q.pop();
            ans.push_back(s1);
            q.push(s1 + "0");
            q.push(s1 + "1");
        }
        for (string x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
