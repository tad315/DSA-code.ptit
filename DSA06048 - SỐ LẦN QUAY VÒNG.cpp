#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int res = -1;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        --n;
        for (int i = 0; i < n; i++)
            if (a[i] > a[i + 1]) res = i + 1;
            
        if (res == -1)
        {
            if (a[0] <= a[n - 1]) cout << 0 << endl;
            else cout << n << endl;
        }
        else cout << res << endl;
    }
    return 0;
}
