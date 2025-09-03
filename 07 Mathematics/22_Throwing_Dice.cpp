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

    long long n;
    cin>>n;

    Matrix<long long, 6> base({
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}
    });

    /*
    Transition
    m[0][0] = m[0][0] + m[0][1] + m[0][2] + m[0][3] + m[0][4] + m[0][5]
    m[0][1] = m[0][0]
    m[0][2] = m[0][1]
    m[0][3] = m[0][2]
    m[0][4] = m[0][3]
    m[0][5] = m[0][4]
    */

    auto res = base.power(n);
    cout<<res.m[0][0];

    return 0;
}
