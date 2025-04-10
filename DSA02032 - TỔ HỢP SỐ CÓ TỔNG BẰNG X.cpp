#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k;
vector <int> a, f;
vector <vector <int>> ans;

void backTrack (int i, int sum)
{
    if (sum == k)
    {
        ans.push_back(f);
        return;
    }

    for (int j = i; j < n; j++)
    {
        if (sum + a[j] <= k)
        {
            f.push_back(a[j]);
            backTrack(j, sum + a[j]);
            f.pop_back();
        }
    }
}

int main()
{
    fast;
    int t; 
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort (a.begin(), a.end());
        backTrack (0, 0);
        if (ans.empty())
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << " ";
        for (auto &x : ans)
        {
            cout << '{';
            for (int i = 0; i < x.size(); i++) 
            {
                if (i > 0) cout << " ";
                cout << x[i];
            }
            cout << "} ";
        }
        cout << endl;
        f.clear();
        ans.clear();
    }
    return 0;
}
