#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int n, k;
    cin >> n >> k;
    int c[10][10];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        p[i] = i;

    vector<vector<int>> res;
    do
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += c[i][p[i]];

        if (sum == k)
        {
            vector<int> way;
            for (int i = 0; i < n; ++i)
                way.push_back(p[i] + 1);
            res.push_back(way);
        }
    }
    while (next_permutation(p.begin(), p.end()));

    cout << res.size() << endl;
    for (auto &x : res)
    {
        for (int pos : x)
            cout << pos << " ";
        cout << endl;
    }
    return 0;
}
