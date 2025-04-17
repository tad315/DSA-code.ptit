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
        vector<string> res;
        q.push("6");
        q.push("8");

        while (!q.empty())
        {
            string top = q.front();
            q.pop();

            if (top.size() > n) continue;
            res.push_back(top);

            q.push(top + "6");
            q.push(top + "8");
        }
        sort(res.begin(), res.end(), [](const string &a, const string &b){
            if (a.size() != b.size())
                return a.size() > b.size();
            return a > b;
        });
        cout << res.size() << endl;
        for (string &x : res)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
