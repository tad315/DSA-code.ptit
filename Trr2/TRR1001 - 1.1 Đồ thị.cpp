#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int n;
vector<vector<int>> a;

void task1(ofstream &outFile) {
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1)
                cnt++;
        outFile << cnt << " ";      
    }
    outFile << endl; 
}

void task2(ofstream &outFile) {
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == 1) {
                ans.emplace_back(i + 1, j + 1);
            }
        }
    }
    outFile << n << " " << ans.size() << endl;
    for (auto &x : ans) {
        outFile << x.first << " " << x.second << endl;
    }
}

int main() {
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");
    fast;
    int t;
    inFile >> t >> n;
    
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> a[i][j];
        }
    }
    
    if (t == 1) task1(outFile);
    else if (t == 2) task2(outFile);
    
    inFile.close();
    outFile.close();
    return 0;
}
