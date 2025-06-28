#include <bits/stdc++.h>
#define int	long long
using namespace std;

//O(n^2);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n ,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    unordered_map<int,pair<int,int>> mp;

    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            int target = x - a[i] - a[j];
            if(mp.find(target)!=mp.end()){
                cout<<i+1<<' '<<j+1<<' '<<mp[target].first+1<<' '<<mp[target].second+1<<'\n';
                return 0;
            }
        }
        for(int j=i+1;j<n;j++){
            mp[a[i]+a[j]] = {i,j};
        }
    }
    
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}

// //O(n^2) better using hashing function
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
// 	for (int i = n - 1; i >= 0; i--) {
// 		for (int j = i - 1; j >= 0; j--) {
// 			int idx = x - a[i] - a[j];
// 			if (hm.find(idx) != hm.end()) {
// 				cout << i + 1 << " " << j + 1 << " " << hm[idx].first + 1 << " " << hm[idx].second + 1 << endl;
// 				return 0;
// 			}
// 		}
// 		for (int j = i + 1; j < n; j++) hm[a[i] + a[j]] = {i, j};
// 	}
// 	cout << "IMPOSSIBLE" << endl;
//     return 0;
// }


////O(n^3)
// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n,x;
//     cin>>n>>x;

//     vector<pair<int,int>> a(n);

//     for(int i=0;i<n;i++){
//         cin>>a[i].first;
//         a[i].second = i+1;
//     }
//     sort(a.begin(),a.end());

//     for(int j=0;j<n;j++){
//         int temp = x - a[j].first;
//         for(int i = j+1;i<n;i++){
//             int target = temp - a[i].first;
//             int l = i+1, r = n-1,sum;
//             while(l<r){
//                 sum = a[l].first + a[r].first;
//                 if(sum==target){
//                     cout<<a[j].second<<' '<<a[i].second<<' '<<a[l].second<<' '<<a[r].second;
//                     return 0;
//                 }
//                 else if(sum>target) r--;
//                 else l++;
//             }
//         }
//     }
    
//     cout<<"IMPOSSIBLE\n";
    
    
//     return 0;
// }
