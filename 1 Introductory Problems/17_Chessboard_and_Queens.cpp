#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> a(8);
    for(auto &i:a) cin>>i;

    auto check = [&](int r, int c){
        for(int i = 0;i<r;i++){
            if(a[i][c]=='Q') return false;
        }
        for(int i = r-1, j = c-1; i>=0 &&j>=0;i--,j--){
            if(a[i][j]=='Q') return false;
        }
        for(int i = r-1, j = c+1; i>=0 &&j<8;i--,j++){
            if(a[i][j]=='Q') return false;
        }
        return true;
    };

    int res = 0;
    auto backtrack = [&](int r, auto &&self){
        if(r==8){
            res++;
            return;
        }
        for(int c = 0; c<8; c++){
            if(a[r][c]=='*') continue;
            if(check(r, c)){
                a[r][c] = 'Q';
                self(r+1, self);
                a[r][c] = '.';
            }
        }
    };

    backtrack(0, backtrack);
    cout<<res;

    return 0;
}
