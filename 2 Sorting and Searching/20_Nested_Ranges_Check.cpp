#include <bits/stdc++.h>
#define int	long long
using namespace std;

//Civilised Approach
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    //left right index
    vector<array<int,3>> a(n);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a[i] = {l,r,i};
    }

    sort(a.begin(),a.end(),[](auto &v1, auto &v2){
            if(v1[0]==v2[0]) return v1[1]>v2[1];
            return v1[0]<v2[0];
    });

    vector<bool>contains(n,0), contained(n,0);
    
    
    int mx = 0;
    for(int i=0;i<n;i++){
        auto &[l, r, ind] = a[i];
        if(r<=mx) contained[ind] = 1;
        mx = max(mx, r);
    }

    int mn = 1e9+1;
    for(int i=n-1;i>=0;i--){
        auto &[l, r, ind] = a[i];
        if(r>=mn) contains[ind] = 1;
        mn = min(mn, r);
    }

    for(auto i: contains) cout<<i<<' ';
    cout<<'\n';
    for(auto i: contained) cout<<i<<' ';
    cout<<'\n';

    return 0;
}



////Dogshit Crazy Approach Using Sparse Table
// class SparseTable {
//     vector<vector<int>> stMin;
//     vector<vector<int>> stMax;
//     vector<int> log;
//     void build(const vector<int> &arr) {
//         int n = arr.size();
//         int maxLog = log2(n) + 1;
//         stMin.assign(n, vector<int>(maxLog));
//         stMax.assign(n, vector<int>(maxLog));
//         log.assign(n + 1, 0);
//         for (int i = 2; i <= n; i++) {
//             log[i] = log[i / 2] + 1;
//         }
//         for (int i = 0; i < n; i++) {
//             stMin[i][0] = arr[i];
//             stMax[i][0] = arr[i];
//         }
//         for (int j = 1; j < maxLog; j++) {
//             for (int i = 0; i + (1 << j) <= n; i++) {
//                 stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
//                 stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
//             }
//         }
//     }
// public:
//     SparseTable(const vector<int>& arr) {
//         build(arr);
//     }
//     int queryMin(int L, int R) {
//         int j = log[R - L + 1];
//         return min(stMin[L][j], stMin[R - (1 << j) + 1][j]);
//     }
//     int queryMax(int L, int R) {
//         int j = log[R - L + 1];
//         return max(stMax[L][j], stMax[R - (1 << j) + 1][j]);
//     }
// };

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n;
//     cin>>n;
//     vector<pair<int,int>> inp(n),temp;
//     for(auto &[a,b]:inp) cin>>a>>b;

//     temp = inp;

//     sort(temp.begin(),temp.end());
    
//     vector<int> starts(n),ends(n);
//     for(int i=0;i<n;i++){
//         starts[i] = temp[i].first;
//         ends[i] = temp[i].second;
//     }

//     SparseTable st(ends);

//     vector<bool> res1(n,0),res2(n,0);

//     for(int i=0;i<n;i++){
//         int s = inp[i].first;
//         int e = inp[i].second;

//         int lb = lower_bound(starts.begin(),starts.end(),s) - starts.begin();
//         if(ends[lb]==e) lb++;
//         int ub = upper_bound(starts.begin(),starts.end(),e) - starts.begin()-1;
//         if(lb<=ub&&st.queryMin(lb,ub)<=e) res1[i] = 1;

//         int newub = upper_bound(starts.begin(),starts.end(),s) - starts.begin()-1;
//         if(ends[newub]==e) newub--;
//         if(newub>=0&&st.queryMax(0,newub)>=e) res2[i] = 1;

//     }

//     for(auto i:res1) cout<<i<<' ';
//     cout<<'\n';
//     for(auto i:res2) cout<<i<<' ';
//     cout<<'\n';

//     return 0;
// }
