#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void solve(vector<int> &a, int n)
{
    vector<vector<int>> steps;
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_ind])
                min_ind = j;
        }
        swap(a[i], a[min_ind]);
        steps.push_back(a);
    }
    for (int i = steps.size() - 1; i >= 0; i--)
    {
        cout << "Buoc " << i + 1 << ": ";
        for (int x : steps[i])
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve(a, n);
    return 0;
}
