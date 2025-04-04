#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = -1;
        if (n == 2){
            cout << ans << endl;
            continue;
        }
        int leftMin[n + 1];
        leftMin[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[leftMin[i - 1]])
                leftMin[i] = i;
            else
                leftMin[i] = leftMin[i - 1];
        }
        int i = n - 1, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (a[j] > a[leftMin[i]])
            {
                ans = max(ans, j - leftMin[i]);
                i--;
            }
            else
                j--;
        }
        cout << ans << endl;
    }
    return 0;
}
