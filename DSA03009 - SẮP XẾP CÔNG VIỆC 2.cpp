#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

struct job
{
    int id, dl, p;
};

bool cmp (job a, job b)
{
    return a.p > b.p;
}

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<job> a(n);
        int maxDl = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].id >> a[i].dl >> a[i].p;
            maxDl = max(maxDl, a[i].dl);
        }
        sort (a.begin(), a.end(), cmp);
        vector<int> slot(maxDl + 1, -1);
        int cnt = 0, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = a[i].dl; j > 0; --j)
            {
                if (slot[j] == -1)
                {
                    slot[j] = a[i].id;
                    ++cnt;
                    sum += a[i].p;
                    break;
                }
            }
        }
        cout << cnt << " " << sum << endl;
    }
    return 0;
}
