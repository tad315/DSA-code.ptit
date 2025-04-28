#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, k;
vector<int> a, f;
vector<vector<int>> ans;

void backTrack(int i, int tmp)
{
    if (i == 0)
    {
        ans.push_back(f);
        return;
    }
    for (int j = min(i, tmp); j >= 1; j--)
    {
        f.push_back(j);
        backTrack(i - j, j);
        f.pop_back();
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        backTrack(n, n);
        for (auto &x : ans)
        {
            cout << '(';
            for (int i = 0; i < x.size(); i++)
            {
                if (i > 0) cout << " ";
                cout << x[i];
            }
                
            cout << ") ";
        }
        cout << endl;
        f.clear();
        ans.clear();
    }
    return 0;
}
