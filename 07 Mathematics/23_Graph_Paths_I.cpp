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
    int n, m;
    vector<vector<T>> d;

    Mat(){
        n = 0;
        m = 0;
        d = vector<vector<T>>();
    }

    Mat(int r, int c){
        n = r;
        m = c;
        d = vector<vector<T>>(n, vector<T>(m, T{}));
    }

    Mat(initializer_list<vector<T>> init){
        n = init.size();
        if(n>0) {
            m = init.begin()->size();
        } 
        else{
            m = 0;
        }
        d = vector<vector<T>>(init.begin(), init.end());
        for(auto &row : d) {
            assert((int)row.size() == m);
        }
    }

    vector<T>& operator[](int i){
        return d[i];
    }

    const vector<T>& operator[](int i) const {
        return d[i];
    }

    int size() const { return n;}
    int nrows() const { return n;}
    int ncols() const { return m;}

    static Mat identity(int dim) {
        Mat I(dim, dim);
        for(int i = 0; i<dim; i++) {
            I.d[i][i] = T{1};
        }
        return I;
    }

    // Matrix × Matrix
    Mat operator*(Mat const& b) const {
        assert(m == b.n);
        Mat res(n, b.m);
        for(int i = 0; i<n; i++) {
            for (int j = 0; j<b.m; j++) {
                T sum = T{};
                for(int k = 0; k<m; k++) {
                    sum += d[i][k] * b.d[k][j];
                }
                res.d[i][j] = sum;
            }
        }
        return res;
    }

    Mat& operator*=(Mat const& b) {
        *this = *this * b;
        return *this;
    }

    // Matrix × Vector
    vector<T> operator*(vector<T> const& v) const {
        assert(m == (int)v.size());
        vector<T> res(n, T{});
        for(int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                res[i] += d[i][j] * v[j];
            }
        }
        return res;
    }

    //exponentiation
    Mat power(long long e) const{
        assert(n == m);
        Mat base = *this;
        Mat result = identity(n);
        while(e>0) {
            if(e&1) result = result * base;
            base = base * base;
            e >>= 1;
        }
        return result;
    }

    Mat operator+(Mat const& b) const {
        assert(n == b.n && m == b.m);
        Mat res(n, m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                res.d[i][j] = d[i][j] + b.d[i][j];
        return res;
    }
    Mat& operator+=(Mat const& b) {
        assert(n == b.n && m == b.m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                d[i][j] += b.d[i][j];
        return *this;
    }

    Mat operator-(Mat const& b) const {
        assert(n == b.n && m == b.m);
        Mat res(n, m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                res.d[i][j] = d[i][j] - b.d[i][j];
        return res;
    }
    Mat& operator-=(Mat const& b) {
        assert(n == b.n && m == b.m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                d[i][j] -= b.d[i][j];
        return *this;
    }

    Mat operator*(T scalar) const {
        Mat res(n, m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                res.d[i][j] = d[i][j] * scalar;
        return res;
    }
    Mat& operator*=(T scalar) {
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                d[i][j] *= scalar;
        return *this;
    }
    Mat operator/(T scalar) const {
        Mat res(n, m);
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                res.d[i][j] = d[i][j] / scalar;
        return res;
    }
    Mat& operator/=(T scalar) {
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                d[i][j] /= scalar;
        return *this;
    }
    friend Mat operator*(T scalar, Mat const& a) {
        return a * scalar;
    }

    // transpose
    Mat transpose() const {
        Mat res(m, n);
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                res.d[j][i] = d[i][j];
            }
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

    int n, m, k;
    cin>>n>>m>>k;

    Mat<Z> base(n, n);

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        base[u][v] += 1;
    }

    Mat res = base.power(k);

    cout<<res[0][n-1];
    
    
    return 0;
}
