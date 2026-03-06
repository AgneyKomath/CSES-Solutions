#include <bits/stdc++.h>
using namespace std;

string manacher(string s){
    int n = s.size();
    int left = 0, right = 0;
    vector<int> len(n);
    int pos = 0;
    for(int i = 0; i < n; i++){
        int l = 1;
        if(i <= right){
            l = min(right - i + 1, len[left + right - i]);
        }
        while(i - l >= 0 && i + l < n && s[i - l] == s[i + l]){
            l++;
            left = i - l + 1;
            right = i + l - 1;
        }
        len[i] = l;
        if(l > len[pos]) pos = i;
    } 
    return s.substr(pos - len[pos] + 1, 2 * len[pos] - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();

    string ip(2 * n + 1, '*');
    for(int i = 0; i < n; i++) ip[2 * i + 1] = s[i];

    string op = manacher(ip);

    for(int i = 1; i < (int)op.size(); i += 2){
        cout<<op[i];
    }

    return 0;
}

// // String Hashing with 2 modulos because only 1 modulo fails O(nlogn)
// struct Shash {
//     using i64 = long long;

//     const int MOD1 = 1000000007;
//     const int MOD2 = 1000000009;

//     struct H {
//         int a, b;
//         bool operator==(const H& o) const { return a == o.a && b == o.b; }
//         bool operator!=(const H& o) const { return !(*this == o); }
//     };

//     string s;
//     int n;
//     int p;

//     vector<int> pw1, pw2;
//     vector<int> prefL1, prefL2, prefR1, prefR2;

//     Shash(const string& _s) {
//         s = _s;
//         n = (int)s.size();
//         p = 90943053;
//         int p1 = p % MOD1; if(p1 < 0) p1 += MOD1;
//         int p2 = p % MOD2; if(p2 < 0) p2 += MOD2;
//         pw1.assign(n + 1, 1);
//         pw2.assign(n + 1, 1);
//         for(int i = 0; i < n; i++){
//             pw1[i + 1] = (i64)pw1[i] * p1 % MOD1;
//             pw2[i + 1] = (i64)pw2[i] * p2 % MOD2;
//         }
//         prefL1.assign(n + 1, 0); prefL2.assign(n + 1, 0);
//         for(int i = 0; i < n; i++){
//             int x = (unsigned char)s[i];
//             prefL1[i + 1] = ((i64)prefL1[i] * p1 + x) % MOD1;
//             prefL2[i + 1] = ((i64)prefL2[i] * p2 + x) % MOD2;
//         }
//         prefR1.assign(n + 1, 0); prefR2.assign(n + 1, 0);
//         for(int i = 0; i < n; i++){
//             int x = (unsigned char)s[n - i - 1];
//             prefR1[i + 1] = ((i64)prefR1[i] * p1 + x) % MOD1;
//             prefR2[i + 1] = ((i64)prefR2[i] * p2 + x) % MOD2;
//         }
//     }

//     H queryL(int l, int r){
//         if(l > r) return {0, 0};
//         int len = r - l + 1;
//         int x1 = (prefL1[r + 1] - (i64)prefL1[l] * pw1[len] % MOD1);
//         if(x1 < 0) x1 += MOD1;
//         int x2 = (prefL2[r + 1] - (i64)prefL2[l] * pw2[len] % MOD2);
//         if(x2 < 0) x2 += MOD2;
//         return {x1, x2};
//     }

//     H queryR(int l, int r){
//         if(l > r) return {0, 0};
//         int len = r - l + 1;
//         int idxL = n - l;
//         int idxR = n - r - 1;
//         int x1 = (prefR1[idxL] - (i64)prefR1[idxR] * pw1[len] % MOD1);
//         if(x1 < 0) x1 += MOD1;
//         int x2 = (prefR2[idxL] - (i64)prefR2[idxR] * pw2[len] % MOD2);
//         if(x2 < 0) x2 += MOD2;
//         return {x1, x2};
//     }

//     bool isPal(int l, int r){
//         return queryL(l, r) == queryR(l, r);
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     string s;
//     cin>>s;

//     int n = s.size();

//     Shash sh(s);

//     auto check = [&](int len)->bool{
//         for(int i = 0; i <= n - len; i++){
//             if(sh.isPal(i, i + len - 1)) return true;
//         }
//         return false;
//     };

//     int lo = 0, hi = n / 2, res = 1;
//     while(lo <= hi){
//         int mid = (lo + hi) / 2;
//         if(check(2 * mid + 1)) {
//             res = max(res, 2 * mid + 1);
//             lo = mid + 1;
//         }
//         else hi = mid - 1;
//     }

//     lo = 1, hi = n / 2;
//     while(lo <= hi){
//         int mid = (lo + hi) / 2;
//         if(check(2 * mid)){
//             res = max(res, 2 * mid);
//             lo = mid + 1;
//         }
//         else hi = mid - 1;
//     }

//     for(int i = 0; i <= n - res; i++){
//         if(sh.isPal(i, i + res - 1)){
//             cout<<s.substr(i, res);
//             break;
//         }
//     }

//     return 0;
// }