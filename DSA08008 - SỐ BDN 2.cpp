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
        int n; 
        cin >> n;
        queue<string> q;
        set<int> s;

        q.push("1");

        while (!q.empty())
        {
            string top = q.front();
            q.pop();

            int rem = 0;
            for (char c : top)
                rem = (rem * 10 + (c - '0')) % n;
            
            if (rem == 0)
            {
                cout << top << endl;
                break;
            }
            
            if (s.count(rem)) continue;
            s.insert(rem);

            q.push(top + "0");
            q.push(top + "1");
        }

    }
    return 0;
}
