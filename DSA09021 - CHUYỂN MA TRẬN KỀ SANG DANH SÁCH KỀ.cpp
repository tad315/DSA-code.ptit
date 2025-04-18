#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int n;
    cin >> n;
    cin.ignore();
    int a[1001][1001];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
                cout << j << " ";
        cout << endl;
    }
    return 0;
}
