#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

using mat = array<array<int, 2>, 2>;

mat mult(mat a, mat b){
    mat res;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            res[i][j] = 0;
            for(int k = 0; k<2; k++){
                int v = 1ll * a[i][k] * b[k][j] % mod;
                res[i][j] = (res[i][j] + v) % mod;
            }
        }
    }
    return res;
}

mat power(mat a, long long b){
    mat res = {{{1, 0}, {0, 1}}};
    for(; b; a = mult(a, a), b /= 2){
        if(b & 1) res = mult(res, a);
    }
    return res;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin>>n;

    /*
    Result Stores 
    [Fn+1, Fn]
    [Fn, Fn-1]
    */

    mat base = {{{1, 1}, {1, 0}}};
    mat res = power(base, n);
    cout<<res[0][1];

    return 0;
}

