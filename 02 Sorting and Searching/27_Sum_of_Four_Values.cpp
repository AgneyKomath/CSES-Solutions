#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    unordered_map<int, pair<int, int>> mp;

    for(int i = 1; i<n; i++){
        for(int j = i+1; j<n; j++){
            int target = x - a[i] - a[j];
            if(mp.count(target)){
                cout<<i+1<<' '<<j+1<<' '<<mp[target].first+1<<' '<<mp[target].second+1<<'\n';
                return 0;
            }
        }
        for(int j = 0; j<i; j++) mp[a[i] + a[j]] = {i, j};
    }

    cout<<"IMPOSSIBLE";
    
    return 0;
}

// // O(n^2) better using hashing function
// mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// struct chash {  /// use most bits rather than just the lowest ones
// 	const uint64_t C = (long long)(2e18 * acos((long double)-1)) + 71;  // large odd number
// 	const int RANDOM = rng();

// 	long long operator()(long long x) const { 
// 		return __builtin_bswap64((x ^ RANDOM) * C);
// 	}
// };
// template <class K, class V> using ht = gp_hash_table<K, V, chash>;

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n,x;
//     cin>>n>>x;
//     vector<int> a(n);
//     for(int &i:a) cin>>i;
//     ht<int, pair<int,int>> hm;
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i - 1; j >= 0; j--) {
//                 int idx = x - a[i] - a[j];
//                 if (hm.find(idx) != hm.end()) {
//                     cout << i + 1 << " " << j + 1 << " " << hm[idx].first + 1 << " " << hm[idx].second + 1 << endl;
//                     return 0;
//                 }
//             }
//             for (int j = i + 1; j < n; j++) hm[a[i] + a[j]] = {i, j};
//         }
//         cout << "IMPOSSIBLE" << endl;
//     return 0;
// }