#include <bits/stdc++.h>
using namespace std;

struct BitwiseTrie{
    using ll = long long;
    struct Node{
        int ch[2]{-1, -1};
        int cnt = 0;
    };

    vector<Node> trie;
    int B;

    BitwiseTrie(int _B = 31){
        B = _B;
        trie.push_back(Node());
    }

    int size(){
        return trie[0].cnt;
    }

    int empty(){
        return size() == 0;
    }

    void add(ll val){
        update(val, 1);
    }

    void erase(ll val){
        update(val, -1);
    }

    void update(ll val, int type){
        int curr = 0;
        trie[curr].cnt += type;
        for(int i = B - 1; i >= 0; i--){
            int v = (val >> i) & 1;
            if(trie[curr].ch[v] == -1){
                trie[curr].ch[v] = trie.size();
                trie.push_back(Node());
            }
            curr = trie[curr].ch[v];
            trie[curr].cnt += type;
        }
    }

    bool exists(ll val){
        int curr = 0;
        for(int i = B - 1; i >= 0; i--) {
            int v = (val >> i) & 1;
            if (trie[curr].ch[v] == -1){
                return false;
            }   
            curr = trie[curr].ch[v];
        }
        return trie[curr].cnt > 0;
    }

    ll maxXor(ll val){
        if(trie[0].cnt == 0) return 0;
        int curr = 0;
        ll res = 0;
        for(int i = B - 1; i >= 0; i--){
            int v = (val >> i) & 1;
            int best = trie[curr].ch[1 - v];

            if(best != -1 && trie[best].cnt > 0){
                res |= 1ll << i;
                curr = best;
            }
            else{
                curr = trie[curr].ch[v];
            }
        }
        return res;
    }

    ll minXor(ll val){
        if(trie[0].cnt == 0) return 0;
        int curr = 0;
        ll res = 0;
        for(int i = B - 1; i >= 0; i--){
            int v = (val >> i) & 1;
            int best = trie[curr].ch[v];

            if(best != -1 && trie[best].cnt > 0){
                curr = best;
            }
            else{
                curr = trie[curr].ch[1 - v];
                res |= 1ll << i;
            }
        }
        return res;
    }

    ll findKth(int k){
        if(k <= 0 || k > trie[0].cnt) return -1;
        int curr = 0;
        ll res = 0;
        for(int i = B - 1; i >= 0; i--){
            int lcnt = 0;
            int lchild = trie[curr].ch[0];
            if(lchild != -1){
                lcnt = trie[lchild].cnt;
            }
            if(k <= lcnt){
                curr = lchild;
            } 
            else{
                k -= lcnt;
                curr = trie[curr].ch[1];
                res |= 1ll << i;
            }
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    // BitwiseTrie tr;
    // int curr = 0, res = 0;
    // for(int i : a){
    //     tr.add(curr);
    //     curr ^= i;
    //     res = max(res, (int)tr.maxXor(curr));
    // }
    // cout<<res;

    // No Struct
    vector<array<int, 2>> tr{{-1, -1}};
    int sum = 0, res = 0;
    for(int i : a){
        int it = 0, val = 0;
        for(int j = 30; j >= 0; j--){
            int b = (sum >> j) & 1;
            if(tr[it][b] == -1){
                tr[it][b] = tr.size();
                tr.push_back({-1, -1});
            }
            it = tr[it][b];
        }
        sum ^= i;
        it = 0;
        for(int j = 30; j >= 0; j--){
            int b = (sum >> j) & 1;
            if(tr[it][1 - b] != -1){
                val |= 1 << j;
                it = tr[it][1 - b];
            }
            else{
                it = tr[it][b];
            }
        }
        res = max(res, val);
    }
    cout<<res;

    return 0;
}