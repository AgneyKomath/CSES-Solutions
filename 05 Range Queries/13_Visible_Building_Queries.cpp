#include <bits/stdc++.h>
using namespace std;

// Binary Lifting
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    int log = __lg(n) + 1;
    vector<vector<int>> table(log, vector<int>(n, n));
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        table[0][i] = st.empty() ? n : st.top();
        st.push(i);
    }

    for(int i = 1; i < log; i++){
        for(int j = 0; j < n; j++){
            if(table[i - 1][j] == n) continue;
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;
        int res = 0;
        for(int i = log - 1; i >= 0; i--){
            if(table[i][l] <= r){
                l = table[i][l];
                res += 1 << i;
            }
        }
        cout<<res + 1<<'\n';
    }

    return 0;
}

// // Range Max Query Approach
// struct SparseTable {
//     int n, maxLog;
//     vector<vector<int>> table;

//     // Change
//     int merge(int a, int b){
//         return max(a, b);
//     }

//     SparseTable(const vector<int> &arr){
//         build(arr);
//     }

//     void build(const vector<int> &arr){
//         n = arr.size();
//         maxLog = __lg(n) + 1;

//         table.assign(n, vector<int>(maxLog));

//         for(int i = 0; i < n; i++){
//             table[i][0] = arr[i];
//         }

//         for(int j = 1; j < maxLog; j++){
//             for(int i = 0; i + (1 << j) <= n; i++){
//                 table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
//             }
//         }
//     }

//     int query(int l, int r){
//         int j = __lg(r - l + 1);
//         return merge(table[l][j], table[r - (1 << j) + 1][j]);
//     }

//     int nextGreat(int id, int val){
//         if(id >= n || query(id, n - 1) <= val) return n;
//         int lo = id, hi = n - 1;
//         while(lo < hi){
//             int mid = (lo + hi) / 2;
//             if(query(id, mid) > val) hi = mid;
//             else lo = mid + 1;
//         }
//         return hi;
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     int n, q;
//     cin>>n>>q;

//     vector<int> a(n);
//     for(int &i : a) cin>>i;

//     stack<int> stack;
//     vector<int> dp(n + 1);
//     dp[n] = 0;
//     for(int i = n - 1; i >= 0; i--){
//         while(!stack.empty() && a[stack.top()] <= a[i]) stack.pop();
//         int id = stack.empty() ? n : stack.top();
//         dp[i] = 1 + dp[id];
//         stack.push(i);
//     }

//     SparseTable st(a);
//     while(q--){
//         int l, r;
//         cin>>l>>r;
//         l--, r--;

//         int res = dp[l];
//         int mx = st.query(l, r);
//         int nid = st.nextGreat(r, mx);
//         res -= dp[nid];

//         cout<<res<<'\n';
//     }

//     return 0;
// }
