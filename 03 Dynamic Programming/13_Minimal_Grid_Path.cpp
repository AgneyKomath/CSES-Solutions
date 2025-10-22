#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<string> a(n);
    for(auto &i : a) cin>>i;

    string res;
    res += a[0][0];

    vector<pair<int, int>> prev, curr;
    prev.emplace_back(0, 0);
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;
    char mn;

    auto update = [&](int r, int c){
        if(r == n || c == n || vis[r][c]) return;
        vis[r][c] = 1;
        if(a[r][c] < mn){
            mn = a[r][c];
            curr.clear();
        }
        if(a[r][c] == mn){
            curr.emplace_back(r, c);
        }
    };

    for(int i = 0; i < 2 * n - 2; i++){
        mn = 'Z' + 1;

        for(auto [r, c] : prev){
            update(r + 1, c);
            update(r, c + 1);
        }
        
        res += mn;
        swap(prev, curr);
    }

    cout<<res;

    return 0;
}
