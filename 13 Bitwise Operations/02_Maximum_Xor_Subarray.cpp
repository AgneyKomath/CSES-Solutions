#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<array<int, 2>> trie;
    trie.push_back({-1, -1});
    
    auto add = [&](int v){
        int curr = 0;
        for(int i = 30; i>=0; i--){
            int b = (v>>i) & 1;
            if(trie[curr][b]==-1){
                trie[curr][b] = trie.size();
                trie.push_back({-1, -1});
            }
            curr = trie[curr][b];
        }
    };

    auto query = [&](int v){
        int curr = 0, res = 0;
        for(int i = 30; i>=0; i--){
            int b = (v>>i) & 1;
            if(trie[curr][1-b]!=-1){
                res += (1<<i);
                curr = trie[curr][1-b];
            }
            else{
                curr = trie[curr][b];
            }
        }
        return res;
    };

    int res = 0;

    int curr = 0;
    for(int i:a){
        add(curr);
        curr ^= i;
        res = max(res, query(curr));
    }
    cout<<res;
    
    return 0;
}
