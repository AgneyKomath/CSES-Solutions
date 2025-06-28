#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int &i:a) cin>>i;

    unordered_map<int,int> mp;
    int i=0,res=0,sz=0;
    for(int j=0;j<n;j++){
        if(mp[a[j]]==0){
            while(sz>=k){
                mp[a[i]]--;
                if(mp[a[i]]==0)sz--;
                i++;
            }
            sz++;
        }
        mp[a[j]]++;

        res += (j-i+1);
    }

    cout<<res<<'\n';
    return 0;
}

// // Coordinate Compression
//#include <bits/stdc++.h>
// #define int	long long
// using namespace std;

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n,k;
//     cin>>n>>k;
//     vector<int> a(n);
//     for(int &i:a) cin>>i;

//     vector<int> b(a);
//     sort(b.begin(), b.end());
//     b.erase(unique(b.begin(), b.end()),b.end());
//     auto compress = [&](int val){
//         return lower_bound(b.begin(),b.end(),val) - b.begin();
//     };
//     for(int &i:a) i = compress(i);
    
//     vector<int> mp(b.size(),0);
//     int res=0,sz=0;
//     for(int j=0, i=0;j<n;j++){
//         if(mp[a[j]]==0){
//             while(sz>=k){
//                 mp[a[i]]--;
//                 if(mp[a[i]]==0)sz--;
//                 i++;
//             }
//             sz++;
//         }
//         mp[a[j]]++;

//         res += (j-i+1);
//     }

//     cout<<res<<'\n';
//     return 0;
// }

