#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool isVal (string s)
{
    if (s.empty()) return 0;
    if (s.size() == 1 && isalpha(s[0])) return 0;
    int cnt = 0;
    for (char i : s)
    {
        if (i == '(') ++cnt;
        else if (i == ')') --cnt;
        if (cnt < 0) return 0;
    }
    return !cnt;
}

int main()
{
    boost;
    int t; 
    cin >> t;
    string s, tmp;
    cin.ignore();
    while (t--)
    {
        cin >> s;
        vector<string> res;
        unordered_map<string, bool> mp;
        queue<string> q;
        mp[s] = 1;
        q.push(s);
        bool check = 0;
        while(q.size())
        {
            string cur = q.front(); q.pop();
            if (isVal(cur))
            {
                res.push_back(cur);
                check = 1;
            }
            if (check) continue;
            for (int i = 0; i < cur.size(); ++i)
            {
                if (isalnum(cur[i])) continue;
                tmp = cur.substr(0, i) + cur.substr(i + 1);
                if (!mp[tmp])
                {
                    mp[tmp] = 1;
                    q.push(tmp);
                }
            }
        }
        if (!check) cout << -1;
        else
        {
            sort(res.begin(), res.end());
            for (string i : res) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
