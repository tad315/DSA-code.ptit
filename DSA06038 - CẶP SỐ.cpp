#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pii pair<int, int>

int merge(vector<int> &a, int l, int r, int m)
{
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l, cnt = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else
        {
            cnt += left.size() - i;
            a[k++] = right[j++];
        }
    }
    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
    return cnt;
}

int mergeSort(vector<int> &a, int l, int r)
{
    int cnt = 0;
    if (l < r)
    {
        int m = (l + r) >> 1;
        cnt += mergeSort(a, l, m);
        cnt += mergeSort(a, m + 1, r);
        cnt += merge(a, l, r, m);
    }
    return cnt;
}

int main()
{
    boost;
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (!(a[i] & 1)) b.push_back(a[i]);
    }
    int ans = 0;
    if (!b.empty()) ans = mergeSort(b, 0, b.size() - 1);
    int sub = 0, i = 0;
    while (i < n)
    {
        if (!(a[i] & 1))
        {
            vector<int> c;
            int j = i;
            while (j < n && !(a[j] & 1)) c.push_back(a[j++]);
            if (c.size() > 1) sub += mergeSort(c, 0, c.size() - 1);
            i = j;
        }
        else ++i;
    }
    cout << ans - sub;
    return 0;
}
