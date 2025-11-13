#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> mp(k, 0);
    set<int> st;
    for(int i = 0; i <= k; i++) st.insert(i);

    auto add = [&](int v){
        if(v >= k) return;
        if(++mp[v] == 1) st.erase(v);
    };

    auto remove = [&](int v){
        if(v >= k) return;
        if(--mp[v] == 0) st.insert(v);
    };

    for(int i = 0; i < n; i++){
        add(a[i]);
        if(i >= k - 1){
            cout<<*st.begin()<<' ';
            remove(a[i - k + 1]);
        }
    }

    return 0;
}

// // 2x Faster Runtime
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, k;
//     cin>>n>>k;

//     vector<int> a(n);
//     for(int &i : a) cin>>i;

//     vector<int> mp(k + 1, 0);
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for(int i = 0; i <= k; i++) pq.push(i);

//     auto add = [&](int v){
//         if(v >= k) return;
//         mp[v]++;
//     };

//     auto remove = [&](int v){
//         if(v >= k) return;
//         if(--mp[v] == 0) pq.push(v);
//     };

//     auto get = [&](){
//         while(mp[pq.top()] != 0) pq.pop();
//         return pq.top();
//     };

//     for(int i = 0; i < n; i++){
//         add(a[i]);
//         if(i >= k - 1){
//             cout<<get()<<' ';
//             remove(a[i - k + 1]);
//         }
//     }

//     return 0;
// }
