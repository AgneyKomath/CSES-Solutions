#include <bits/stdc++.h>
using namespace std;

template<int B = 62>
struct XorBasis{
    using ll = long long;
    int rank = 0;
    array<ll, B> basis{};

    XorBasis(){};

    template<typename T>
    XorBasis(vector<T> &a){
        for(auto x : a) insert(x);
    }

    void insert(ll v){
        for(int i = B - 1; i >= 0; i--){
            if((v >> i) & 1){
                if(!basis[i]){
                    basis[i] = v;
                    rank++;
                    return;
                }
                else v ^= basis[i];
            }
        }
    }

    ll numXor(){
        return 1ll << rank;
    }

    ll maxXor(){
        ll res = 0;
        for(int i = B - 1; i >= 0; i--){
            res = max(res, res ^ basis[i]);
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    XorBasis<31> basis;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        basis.insert(x);
    }

    cout<<basis.maxXor();

    return 0;
}