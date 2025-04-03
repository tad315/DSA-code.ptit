#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n)
{
    vector<vector<int>> steps;
    bool check;

    for (int i = 0; i < n; i++)
    {
        check = 0;
        for (int j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                check = 1;
            }

        if (!check)
            break;
        steps.push_back(a);
    }

    for (int i = steps.size() - 1; i >= 0; i--)
    {
        cout << "Buoc " << i + 1 << ": ";
        for (int x : steps[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(a, n);
    }
    return 0;
}
