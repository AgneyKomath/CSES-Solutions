#include <bits/stdc++.h>
using namespace std;

// Z Algorithm O(n)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }

    for(int i = 1; i < n; i++){
        if(z[i] == n - i){
            cout<<i<<' ';
        }
    }
    cout<<n;

    return 0;
}

// // String Hashing O(n)
// struct Shash{
//     using u64 = uint64_t;
//     string s;
//     int n;
//     u64 p;
//     vector<u64> pw, pref;

//     Shash(string _s){
//         s = _s;
//         n = s.size();
//         p = std::chrono::steady_clock::now().time_since_epoch().count() | 1ULL;
//         if(p < (1ULL << 20)) p |= (1ULL << 20);
//         pw.resize(n + 1);
//         pw[0] = 1;
//         for(int i = 0; i < n; i++) pw[i + 1] = pw[i] * p;
//         pref.assign(n + 1, 0);
//         for(int i = 0; i < n; i++){
//             pref[i + 1] = pref[i] * p + (u64)s[i];
//         }
//     }

//     u64 query(int l, int r){
//         if(l > r) return 0;
//         return pref[r + 1] - pref[l] * pw[r - l + 1];
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     string s;
//     cin>>s;

//     int n = s.size();

//     Shash sh(s);

//     for(int i = 1; i < n; i++){
//         if(sh.query(i, n - 1) == sh.query(0, n - i - 1)){
//             cout<<i<<' ';
//         }
//     }
//     cout<<n;

//     return 0;
// }