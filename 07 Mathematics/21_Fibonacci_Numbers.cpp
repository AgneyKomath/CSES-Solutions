#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
template<class T>
constexpr T power(T a, ll b, T res = 1) {
    for (; b; b /= 2, a *= a) {
        if (b & 1)
            res *= a;
    }
    return res;
}

template<ll P>
constexpr ll mulMod(ll a, ll b) {
    return (a * b) % P;
}

template<ll P>
struct ModInt {
    ll x;

    constexpr ModInt() : x(0) {}

    template<std::integral T>
    constexpr ModInt(T x_) {
        ll modVal = P;
        ll v = x_ % modVal;
        if (v < 0)
            v += modVal;
        x = v;
    }

    constexpr static ll mod() { return P; }

    constexpr ll val() const { return x; }

    constexpr ModInt operator-() const {
        return ModInt(x == 0 ? 0 : P - x);
    }

    constexpr ModInt inv() const {
        return power(*this, P - 2);
    }

    constexpr ModInt &operator*=(const ModInt &rhs) {
        x = mulMod<P>(x, rhs.x);
        return *this;
    }
    constexpr ModInt &operator+=(const ModInt &rhs) {
        x += rhs.x;
        if (x >= P)
            x -= P;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs) {
        x -= rhs.x;
        if (x < 0)
            x += P;
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &rhs) {
        return *this *= rhs.inv();
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        ll t;
        is >> t;
        a = ModInt(t);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(const ModInt &lhs, const ModInt &rhs) {
        return lhs.x == rhs.x;
    }
    friend constexpr std::strong_ordering operator<=>(const ModInt &lhs, const ModInt &rhs) {
        return lhs.x <=> rhs.x;
    }
};

using Z = ModInt<1000000007>;

template<typename T>
struct Mat{

    vector<vector<T>> identity(int n){
        vector<vector<T>> res(n, vector<T>(n, 0));
        for(int i = 0; i<n; i++) res[i][i] = 1;
        return res;
    }

    vector<vector<T>> multiply(vector<vector<T>> &a, vector<vector<T>> &b){
        int n = a.size(), w = a[0].size(), m = b[0].size();
        vector<vector<T>> res(n, vector<T>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                for(int k = 0; k<w; k++){
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
    
    vector<T> multiply(vector<T> &a, vector<vector<T>> &b){
        int w = a.size(), m = b[0].size();
        vector<T> res(m);
        for(int j = 0; j<m; j++){
            for(int k = 0; k<w; k++){
                res[j] += a[k] * b[k][j];
            }
        }
        return res;
    }

    vector<vector<T>> power(vector<vector<T>> &a, long long b){
        int n = a.size();
        vector<vector<T>> res = identity(n);
        while(b>0){
            if(b&1) res = multiply(res, a);
            a = multiply(a, a);
            b /= 2;
        }
        return res;
    }

};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    Mat<Z> mat;

    vector<vector<Z>> base{{1, 1}, {1, 0}};

    vector<vector<Z>> res = mat.power(base, n);

    /*
    Result Stores 
    [Fn+1, Fn]
    [Fn, Fn-1]
    */
    cout<<res[0][1]<<'\n';
    
    return 0;
}
