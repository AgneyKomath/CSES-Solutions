#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18;

template<typename T, int N>
struct Matrix{
    T m[N][N];

    static Matrix ident(){
        Matrix res{};
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(i != j) res.m[i][j] = INF;
            }
        }
        return res;
    }

    // Modify
    Matrix operator*(const Matrix &b) const{
        Matrix res{};
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                res.m[i][j] = INF;
                for(int k = 0; k<N; k++){
                    res.m[i][j] = min(res.m[i][j], m[i][k] + b.m[k][j]);
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
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            base.m[i][j] = INF;
        }
    }

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        base.m[u][v] = min(base.m[u][v], (long long) w);
    }
    
    auto res = base.power(k);
    cout<<(res.m[0][n-1]==INF?-1:res.m[0][n-1]);

    return 0;
}
