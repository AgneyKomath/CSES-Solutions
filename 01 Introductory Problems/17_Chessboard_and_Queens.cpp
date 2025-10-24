#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 8;

    vector<string> a(n);
    for(auto &i : a) cin>>i;

    auto check = [&](int r, int c){
        if(a[r][c] == '*') return false;
        for(int i = 0, j = c; i < r; i++){
            if(a[i][j] == 'Q') return false;
        }
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--){
            if(a[i][j] == 'Q') return false;
        }
        for(int i = r, j = c; i >= 0 && j < n; i--, j++){
            if(a[i][j] == 'Q') return false;
        }
        return true;
    };

    int res = 0;
    auto f = [&](int r, auto &&f){
        if(r == n){
            res++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(check(r, i)){
                a[r][i] = 'Q';
                f(r + 1, f);
                a[r][i] = '.';
            }
        }
    };

    f(0, f);

    cout<<res;

    return 0;
}
