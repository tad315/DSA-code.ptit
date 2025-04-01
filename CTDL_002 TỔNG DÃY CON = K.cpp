#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;
vector <int> v;
vector <bool> f;
vector <vector<bool>> ans;

void check (){
    int sum = 0;
    for (int i = 1; i<=n; ++i){
        sum += v[i] * f[i];
    }
    if (sum == k) ans.push_back(f); 
}

void Try (int i){
    for (int j =0; j<=1; ++j){
        f[i] = j;
        if (i==n) check();
        else Try(i+1);
    }
}

int main(){
    cin >> n >> k;
    v.resize(n+1);
    f.resize(n+1);
    for (int i = 1; i<=n; ++i) cin >> v[i];
    Try(1);
    for (vector<bool> &x : ans){
        for (int j =1; j <=n; ++j){
            if (x[j]) cout << v[j] << " ";
        }
        cout << endl;
    }
    cout << ans.size();
    return 0;
}
