#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());
    
    auto comp = [&](pair<int, int> & a, pair<int, int> & b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    };

    vector<int> mp(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

    auto add = [&](int v){
        pq.emplace(++mp[v], v);
    };

    auto remove = [&](int v){
        mp[v]--;
        if(mp[v]) pq.emplace(mp[v], v);
    };

    auto get = [&](){
        while(1){
            auto [f, v] = pq.top();
            if(mp[v] != f) pq.pop();
            else break;
        }
        return b[pq.top().second];
    };

    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        add(a[i]);
        if(i >= k - 1){
            cout<<get()<<' ';
            remove(a[i - k + 1]);
        }
    }

    return 0;
}
