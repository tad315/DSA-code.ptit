#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int minSwapsToSort(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; ++i) pos[i] = {arr[i], i};

    sort(pos.begin(), pos.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] || pos[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j])
        {
            visited[j] = true;
            j = pos[j].second;
            ++cycle_size;
        }

        if (cycle_size > 1)
            swaps += (cycle_size - 1);
    }

    return swaps;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << minSwapsToSort(a) << '\n';
    }
    return 0;
}
