#include <bits/stdc++.h>
using namespace std;

// Hashing O(nlogn)
struct Shash{
    using u64 = uint64_t;
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
    s += s;

    Shash sh(s);
    auto cmp = [&](int i, int j){
        int lo = 0, hi = n - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(sh.query(i, i + mid) != sh.query(j, j + mid)){
                hi = mid;
            }
            else lo = mid + 1;
        }
        return s[i + lo] > s[j + lo];
    };

    int p = 0;
    for(int i = 1; i < n; i++){
        if(cmp(p, i)) p = i;
    }

    cout<<s.substr(p, n);

    return 0;
}

// // Booth Algorithm O(n)
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     string s;
//     cin>>s;

//     s += s;
//     int p = 0, n = s.size();

//     vector<int> f(n, -1);
//     for(int l = 1, r = 1; r < n; r++){
//         for(l = f[r - p - 1]; l != -1 && s[p + l + 1] != s[r]; l = f[l]){
//             if(s[l + p + 1] > s[r]) p = r - l - 1;
//         }
//         if(l == -1 && s[p + l + 1] != s[r]){
//             if(s[p + l + 1] > s[r]) p = r;
//             f[r - p] = -1;
//         }
//         else{
//             f[r - p] = l + 1;
//         }
//     }

//     cout<<s.substr(p, n / 2);

//     return 0;
// }
