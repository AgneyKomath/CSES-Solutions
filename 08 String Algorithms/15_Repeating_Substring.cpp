#include <bits/stdc++.h>
using namespace std;

struct SuffixArray{
    // Suffix Array by Fusion15
    const int MXCHAR = 256;

    string s, t;
    int n;
    vector<int> p, c, lcp;

    SuffixArray(string &_s){
        s = _s;
        t = s;
        t.push_back((unsigned char)0);
        n = t.size();
        build_sa();
        build_lcp();
    }

    void build_sa(){
        p.resize(n);
        c.resize(n);
        vector<int> cnt(max(MXCHAR, n), 0);
        for(int i = 0; i < n; i++) cnt[(unsigned char)t[i]]++;
        for(int i = 1; i < MXCHAR; i++) cnt[i] += cnt[i - 1];
        for(int i = 0; i < n; i++){
            p[--cnt[(unsigned char)t[i]]] = i;
        }
        c[p[0]] = 0;
        int classes = 1;
        for(int i = 1; i < n; i++){
            if(t[p[i]] != t[p[i - 1]]) classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for(int h = 0; (1 << h) < n; h++){
            for(int i = 0; i < n; i++){
                pn[i] = p[i] - (1 << h);
                if(pn[i] < 0) pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
            for(int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
            for(int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for(int i = 1; i < n; i++){
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
                if(cur != prev) classes++;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
    }

    void build_lcp(){
        lcp.assign(n - 1, 0);
        vector<int> rank(n);
        for(int i = 0; i < n; i++) rank[p[i]] = i;
        int k = 0;
        for(int i = 0; i < n; i++){
            int r = rank[i];
            if(r == n - 1){
                k = 0;
                continue;
            }
            int j = p[r + 1];
            while(i + k < n && j + k < n && t[i + k] == t[j + k]) k++;
            lcp[r] = k;
            if(k) k--;
        }
    }

    vector<int> getSA(){
        return vector<int>(p.begin() + 1, p.end());
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    SuffixArray sa(s);

    int mx = max_element(sa.lcp.begin(), sa.lcp.end()) - sa.lcp.begin();
    if(sa.lcp[mx] == 0) cout<<"-1";
    else cout<<s.substr(sa.p[mx], sa.lcp[mx]);

    return 0;
}