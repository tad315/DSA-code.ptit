#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        int left = 0, res = -1;
        for (int i = 0; i < n; i++)
        {
            int right = sum - a[i] - left;
            if (left == right)
            {
                res = i + 1;
                break;
            }
            left += a[i];
        }
        cout << res << endl;
    }
    return 0;
}
