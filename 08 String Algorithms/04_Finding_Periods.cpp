#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
struct Shash{
    string s;
    int n;
    u64 p;
    vector<u64> pw, pref;

    Shash(string _s){
        s = _s;
        n = s.size();

        p = std::chrono::steady_clock::now().time_since_epoch().count() | 1ULL;
        if(p < (1ULL << 20)) p |= (1ULL << 20);

        pw.resize(n + 1);
        pw[0] = 1;
        for(int i = 0; i < n; i++) pw[i + 1] = pw[i] * p;
        pref.assign(n + 1, 0);
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] * p + (u64)s[i];
        }
    }

    u64 query(int l, int r){
        if(l > r) return 0;
        return pref[r + 1] - pref[l] * pw[r - l + 1];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    Shash sh(s);

    for(int i = 1; i <= n; i++){
        bool f = true;
        for(int j = i; j < n; j += i){
            int l = j, r = min(n - 1, j + i - 1);
            if(sh.query(l, r) != sh.query(0, r - l)){
                f = false;
                break;
            }
        }
        if(f) cout<<i<<' ';
    }

    return 0;
}
