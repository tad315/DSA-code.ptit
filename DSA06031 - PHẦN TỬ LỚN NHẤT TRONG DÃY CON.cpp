#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        deque<int> dp;
        for (int i = 0; i < k; i++)
        {
            while (!dp.empty() && a[i] >= a[dp.back()])
                dp.pop_back();
            dp.push_back(i);
        }
        for (int i = k; i < n; i++)
        {
            cout << a[dp.front()] << " ";
            while (!dp.empty() && dp.front() <= i - k)
                dp.pop_front();
            while (!dp.empty() && a[i] >= a[dp.back()])
                dp.pop_back();
            dp.push_back(i);
        }
        cout << a[dp.front()] << endl;
    }
    return 0;
}
