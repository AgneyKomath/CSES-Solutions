#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> left(n), right(n);

    vector<int> stack;
    for(int i = 0; i < n; i++){
        while(!stack.empty() && a[stack.back()] <= a[i]) stack.pop_back();
        left[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }

    stack.clear();
    for(int i = n - 1; i >= 0; i--){
        while(!stack.empty() && a[stack.back()] <= a[i]) stack.pop_back();
        right[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }

    // This is basically a DAG. Problem reduces to longest path in DAG
    vector<int> dp(n, -1);

    auto dfs = [&](int id, auto &&dfs){
        if(id == -1) return 0;
        if(dp[id] != -1) return dp[id];
        dp[id] = 1 + max(dfs(left[id], dfs), dfs(right[id], dfs));
        return dp[id];
    };

    int res = 1;
    for(int i = 0; i < n; i++){
        res = max(res, dfs(i, dfs));
    }

    cout<<res;

    return 0;
}
