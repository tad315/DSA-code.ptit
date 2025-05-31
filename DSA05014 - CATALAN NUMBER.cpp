#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
const int MAX = 10000;
vector <int> catalan[101];

vector <int> multiply (vector <int> &a, int b)
{
    vector <int> res;
    int num = 0;
    for (int x : a)
    {
        int tmp = x * b + num;
        res.push_back(tmp % 10);
        num = tmp / 10;
    }
    while (num)
    {
        res.push_back(num % 10);
        num /= 10;
    }
    return res;
}

vector<int> div (vector<int> &a, int b)
{
    vector<int> res;
    int r = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        r = r * 10 + a[i];
        res.push_back(r / b);
        r %= b;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

void pre()
{
    catalan[0] = {1};
    for (int i = 1; i <= 100; ++i)
    {
        vector<int> num = {1};
        for (int j = 2 * i; j > i; --j) num = multiply(num, j);
        for (int j = 1; j <= i; ++j) num = div(num, j);
        num = div(num, i + 1);
        catalan[i] = num;
    }
}

void print (vector<int> &a)
{
    for (int i = a.size() - 1; i >= 0; --i) cout << a[i];
    cout << endl;
}

int main()
{
    boost;
    pre();
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        print(catalan[n]);
    }
    return 0;
}
