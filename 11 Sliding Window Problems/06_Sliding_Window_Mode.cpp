#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    unordered_map<int, int> freq;
    map<int, set<int>> mp;

    auto add = [&](int v)->void{
        int pv = freq[v];
        freq[v]++;
        int nv = freq[v];
        mp[pv].erase(v);
        if(mp[pv].empty()) mp.erase(pv);
        mp[nv].insert(v);
    };

    auto remove = [&](int v)->void{
        int pv = freq[v];
        freq[v]--;
        int nv = freq[v];
        mp[pv].erase(v);
        if(mp[pv].empty()) mp.erase(pv);
        if(nv != 0) mp[nv].insert(v);
    };
    
    auto mode = [&]()->int{
        auto &s = mp.rbegin()->second;
        return *s.begin();
    };

    for(int i = 0, j = 0; j<n; j++){
        add(a[j]);
        if(j-i+1==k){
            cout<<mode()<<' ';
            remove(a[i++]);
        }
    }
    
    return 0;
}
