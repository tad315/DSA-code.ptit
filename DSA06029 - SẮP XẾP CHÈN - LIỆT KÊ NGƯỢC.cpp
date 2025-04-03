#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n) {
    vector<vector<int>> steps;
    steps.push_back({a[0]});
    
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        steps.push_back(vector<int>(a.begin(), a.begin() + i + 1));
    }
    
    for (int i = steps.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i << ": ";
        for (int x : steps[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, n);
    return 0;
}
