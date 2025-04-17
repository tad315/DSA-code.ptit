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
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        vector <string> v;
        stringstream ss(s);
        string token;
        while (ss >> token) v.push_back(token);
        for (int i = v.size() - 1; i >= 0; --i)
        {
            cout << v[i];
            if (i > 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
