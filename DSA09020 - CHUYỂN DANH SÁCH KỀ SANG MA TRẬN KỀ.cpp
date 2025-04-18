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
    
    int mt[1001][1001] = {};
    
    for (int i = 1; i <= n; ++i)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        while (ss >> x)
        {
            mt[i][x] = 1;
            mt[x][i] = 1;
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << mt[i][j];
            if (j < n) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
