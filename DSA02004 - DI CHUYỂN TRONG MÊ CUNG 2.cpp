#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int n, a[15][15];
bool f[15][15];
vector<string> ans;

void backTrack(int i, int j, string s)
{
    if (i == n && j == n)
    {
        ans.push_back(s);
        return;
    }
    
    if (i + 1 <= n && a[i + 1][j] == 1 && !f[i + 1][j])
    {
        f[i + 1][j] = 1;
        backTrack(i + 1, j, s + 'D');
        f[i + 1][j] = 0;
    }

    if (j - 1 >= 1 && a[i][j - 1] == 1 && !f[i][j - 1])
    {
        f[i][j - 1] = 1;
        backTrack(i, j - 1, s + 'L');
        f[i][j - 1] = 0;
    }

    if (j + 1 <= n && a[i][j + 1] == 1 && !f[i][j + 1])
    {
        f[i][j + 1] = 1;
        backTrack(i, j + 1, s + 'R');
        f[i][j + 1] = 0;
    }

    if (i - 1 >= 1 && a[i - 1][j] == 1 && !f[i - 1][j])
    {
        f[i - 1][j] = 1;
        backTrack(i - 1, j, s + 'U');
        f[i - 1][j] = 0;
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                f[i][j] = 0;
            }
        }
        ans.clear();
        
        if (a[1][1] == 0 || a[n][n] == 0) {
            cout << -1 << endl;
            continue;
        }
        
        f[1][1] = 1;
        backTrack(1, 1, "");
        
        if (ans.empty()) {
            cout << -1 << endl;
        } else {
            sort(ans.begin(), ans.end());
            for (string x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
