#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    boost;
    int n, s;
    cin >> n >> s;
    if (s == 0)
    {
        if (n == 1) cout << "0 0" << endl;
        else cout << "-1 -1" << endl;
        return 0;
    }

    if (s > 9 * n)
    {
        cout << "-1 -1" << endl;
        return 0;
    }

    vector<int> minNum(n, 0);
    int sum = s;
    for (int i = n - 1; i >= 0; --i)
    {
        minNum[i] = min(sum, 9);
        sum -= minNum[i];
    }
    if (minNum[0] == 0)
    {
        for (int i = 1; i < n; ++i)
        {
            if (minNum[i] > 0)
            {
                --minNum[i];
                minNum[0] = 1;
                break;
            }
        }
    }

    vector<int> maxNum(n, 0);
    sum = s;
    for (int i = 0; i < n; ++i) 
    {
        maxNum[i] = min(sum, 9);
        sum -= maxNum[i];
    }
    for (int i = 0; i < n; ++i) cout << minNum[i];
    cout << " ";
    for (int i = 0; i < n; ++i) cout << maxNum[i];
    cout << endl;
    return 0;
}
