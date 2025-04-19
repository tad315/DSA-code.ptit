#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        
        vector<int> inDeg(v + 1, 0), outDeg(v + 1, 0);
        for (int i = 0; i < e; ++i)
        {
            int x, y;
            cin >> x >> y;
            ++inDeg[y];
            ++outDeg[x];
        }
        bool check = 1;
        for (int i = 1; i <= v; ++i)
        {
            if (inDeg[i] != outDeg[i])
            {
                check = 0;
                break;
            }
        }
        cout << (check ? 1 : 0) << endl;
        
    }
    return 0;
}
