#include <bits/stdc++.h>
using namespace std;

struct BIT{
    //Fenwick Tree by Fusion15
    vector<int> tree;
    int n;
    
    BIT(int _n){
        n = _n;
        tree.resize(n+1, 0);
    }
    
    void add(int ind, int val){
        for(int i=ind+1; i<=n; i += i&-i){
            tree[i] += val;
        }
    }
    
    int query(int ind){
        int sum = 0;
        for(int i = ind+1; i>0; i -= i&-i){
            sum += tree[i];
        }
        return sum;
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<array<int, 3>> a(n);
    for(int i = 0; i<n; i++){
        int s, e;
        cin>>s>>e;
        a[i] = {s, e, i};
    }
    
    // Coordinate Compression
    vector<int> b;
    for(auto [s, e, i]:a){
        b.push_back(s);
        b.push_back(e);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for(auto &[s, e, i]:a){
        e = lower_bound(b.begin(), b.end(), e) - b.begin();
        s = lower_bound(b.begin(), b.end(), s) - b.begin();
    }
    int sz = b.size();
    
    // sort by end times in ascending then start times in descending
    sort(a.begin(), a.end(), [](auto &a1, auto &a2){
        if(a1[1] != a2[1]) return a1[1]<a2[1];
        return a1[0]>a2[0];
    });

    // How many ranges does a range contain
    BIT bit1(sz);
    vector<int> contains(n, 0);
    for(int i = 0; i<n; i++){
        auto [s, e, id] = a[i];
        contains[id] = bit1.query(s, e);
        bit1.add(s, 1);
    }

    // How many ranges is a range contained in
    BIT bit2(sz);
    vector<int> contained(n, 0);
    for(int i = n-1; i>=0; i--){
        auto [s, e, id] = a[i];
        contained[id] = bit2.query(0, s);
        bit2.add(s, 1);
    }

    for(int i:contains) cout<<i<<' ';
    cout<<'\n';

    for(int i:contained) cout<<i<<' ';
    cout<<'\n';
    
    return 0;
}