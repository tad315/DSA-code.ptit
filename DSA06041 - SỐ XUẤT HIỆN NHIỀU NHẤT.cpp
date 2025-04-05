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
        for (int i = 0; i < n; i++) cin >> a[i];
        int tmp = a[0];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == tmp) cnt++;
            else cnt--;
            if (cnt == 0)
            {
                tmp = a[i];
                cnt = 1;
            }
        }
        cnt = 0;
        for (int i: a)
        {
            if (i == tmp) cnt++;
        }

        if (cnt > n / 2) cout << tmp << endl;
        else cout << "NO\n";
    }
    return 0;
}
