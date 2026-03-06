#include <bits/stdc++.h>
using namespace std;

// Suffix Automata Solution O(n)
struct SAM{
    // Suffix Automata by Fusion15
    struct state{
        int len, link, next[26];
    };

    string s;

    vector<state> st;
    int sz, last, n;

    SAM(string &_s){
        s = _s;
        n = s.size();
        st.resize(2 * n + 1);
        init();
        for(char c : s) extend(c);
    }

    void init(){
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void extend(char c){
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        int p = last;
        int code = c - 'a';
        while(p != -1 && st[p].next[code] == -1){
            st[p].next[code] = cur;
            p = st[p].link;
        }
        if(p == -1){
            st[cur].link = 0;
        }
        else{
            int q = st[p].next[code];
            if(st[p].len + 1 == st[q].len){
                st[cur].link = q;
            }
            else{
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].link = st[q].link;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                while(p != -1 && st[p].next[code] == q){
                    st[p].next[code] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    long long distinctSubstrings(){
        long long res = 0;
        for(int u = 1; u < sz; u++){
            res += st[u].len - st[st[u].link].len;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    SAM sam(s);

    cout<<sam.distinctSubstrings();

    return 0;
}

// // Suffix Array Solution O(nlogn)
// struct SuffixArray{
//     // Suffix Array by Fusion15
//     string s, t;
//     int n;
//     vector<int> p, c, lcp;

//     SuffixArray(string &_s){
//         s = _s;
//         t = s;
//         t.push_back('$');
//         n = t.size();
//         build();
//         build_lcp();
//     }

//     void build(){
//         p.resize(n);
//         c.resize(n);

//         vector<int> cnt(max(256, n), 0);
//         for(int i = 0; i < n; i++) cnt[(unsigned char)t[i]]++;
//         for(int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
//         for(int i = 0; i < n; i++){
//             p[--cnt[(unsigned char)t[i]]] = i;
//         }

//         c[p[0]] = 0;

//         int classes = 1;
//         for(int i = 1; i < n; i++){
//             if(t[p[i]] != t[p[i - 1]]) classes++;
//             c[p[i]] = classes - 1;
//         }

//         vector<int> pn(n), cn(n);
//         for(int h = 0; (1 << h) < n; h++){
//             for(int i = 0; i < n; i++){
//                 pn[i] = p[i] - (1 << h);
//                 if(pn[i] < 0) pn[i] += n;
//             }

//             fill(cnt.begin(), cnt.begin() + classes, 0);
//             for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
//             for(int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
//             for(int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

//             cn[p[0]] = 0;
//             classes = 1;
//             for(int i = 1; i < n; i++){
//                 pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
//                 pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
//                 if(cur != prev) classes++;
//                 cn[p[i]] = classes - 1;
//             }
//             c.swap(cn);
//         }
//     }

//     void build_lcp(){
//         lcp.assign(n - 1, 0);

//         vector<int> rank(n);
//         for(int i = 0; i < n; i++) rank[p[i]] = i;

//         int k = 0;
//         for(int i = 0; i < n; i++){
//             int r = rank[i];
//             if(r == n - 1){
//                 k = 0;
//                 continue;
//             }
//             int j = p[r + 1];
//             while(i + k < n && j + k < n && t[i + k] == t[j + k]) k++;
//             lcp[r] = k;
//             if(k) k--;
//         }
//     }

//     vector<int> getSA(){
//         vector<int> res;
//         res.reserve(n - 1);
//         for(int i = 0; i < n; i++){
//             if(p[i] != n - 1) res.push_back(p[i]);
//         }
//         return res;
//     }
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     string s;
//     cin>>s;

//     int n = s.size();

//     SuffixArray SA(s);

//     long long res = 1ll * n * (n + 1) / 2;
//     for(int i = 0; i < n; i++) res -= SA.lcp[i];

//     cout<<res;

//     return 0;
// }