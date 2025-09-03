#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

template<typename T, int N>
struct Matrix{
    T m[N][N];

    static Matrix ident(){
        Matrix res{};
        for(int i = 0; i < N; i++){
            res.m[i][i] = T(1);
        }
        return res;
    }

    // Modify
    Matrix operator*(const Matrix &b) const{
        Matrix res{};
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                res.m[i][j] = 0;
                for(int k = 0; k<N; k++){
                    res.m[i][j] += m[i][k] * b.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }

    Matrix power(long long b){
        Matrix a = *this;
        Matrix res = ident();
        for(; b; a = a * a, b /= 2){
            if(b & 1) res = res * a;
        }
        return res;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    Matrix<long long, 100> base{};

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        base.m[u][v]++;
    }

    auto res = base.power(k);
    cout<<res.m[0][n-1];

    return 0;
}
