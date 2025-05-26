#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

string s;
vector<pair<int, int>> p;
set<string> res;

void dfs(int i, vector<bool> &rm) {
    if (i == p.size()) {
        set<int> idx;
        for (int j = 0; j < p.size(); ++j)
            if (rm[j]) idx.insert(p[j].first), idx.insert(p[j].second);

        string t;
        for (int j = 0; j < s.size(); ++j)
            if (!idx.count(j)) t += s[j];

        if (t != s) res.insert(t);
        return;
    }
    rm[i] = 0;
    dfs(i + 1, rm);
    rm[i] = 1;
    dfs(i + 1, rm);
}

int main() {
    boost;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            p.emplace_back(st.top(), i);
            st.pop();
        }
    }
    vector<bool> rm(p.size(), 0);
    dfs(0, rm);
    for (auto &x : res) cout << x << '\n';
    return 0;
}
