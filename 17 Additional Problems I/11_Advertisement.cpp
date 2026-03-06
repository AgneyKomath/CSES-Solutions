#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    long long res = 0;

    vector<int> stack{-1};
    for(int i = 0; i < n; i++){
        while(stack.back() != -1 && a[stack.back()] >= a[i]){
            int v = a[stack.back()];
            stack.pop_back();
            res = max(res, 1ll * v * (i - stack.back() - 1));
        }
        stack.push_back(i);
    }

    for(int i = 0; i + 1 < stack.size(); i++){
        res = max(res, 1ll * a[stack[i + 1]] * (n - stack[i] - 1));
    }
    cout<<res;

    return 0;
}