#include <bits/stdc++.h>
using namespace std;

struct KMP{
    //KMP Struct by Fusion15
    string s;
    KMP(string _s){
        s = _s;
    }

    vector<int> LPS(string &p) {
        int m = p.size(), len = 0;
        vector<int> lps(m);
        for(int i = 1; i < m; ) {
            if(p[i] == p[len]) lps[i++] = ++len;
            else if(len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return lps;
    }
    
    int find(string p) {
        if(p.empty()) return 0;
        vector<int> lps = LPS(p);
        int n = s.size(), m = p.size(), i = 0, j = 0;
        while (i<n) {
            if(s[i]==p[j]){
                i++;
                j++;
            }
            if(j==m) return i-j;
            else if(i<n && s[i]!=p[j]) {
                if(j>0) j = lps[j-1];
                else i++;
            }
        }
        return n;
    }

    bool contains(string p){
        return find(p) != s.size();
    }
    
    vector<int> findAll(string p) {
        if(p.empty()) return {};
        vector<int> res, lps = LPS(p);
        int n = s.size(), m = p.size(), i = 0, j = 0;
        while (i<n) {
            if(s[i]==p[j]){
                i++;
                j++;
            }
            if(j==m) {
                res.push_back(i-j);
                j = lps[j-1];
            } 
            else if(i<n && s[i]!=p[j]) {
                if(j>0) j = lps[j-1];
                else i++;
            }
        }
        return res;
    }

    int Cnt(string p){
        return findAll(p).size();
    }

    vector<int> findAllNoOverlap(string p){
        if(p.empty()) return {};
        vector<int> res, lps = LPS(p);
        int n = s.size(), m = p.size(), i = 0, j = 0;
        while (i<n) {
            if(s[i]==p[j]){
                i++;
                j++;
            }
            if(j==m) {
                res.push_back(i-j);
                j = 0;
            } 
            else if(i<n && s[i]!=p[j]) {
                if(j>0) j = lps[j-1];
                else i++;
            }
        }
        return res;
    }

    int CntNoOverlap(string p){
        return findAllNoOverlap(p).size();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;
    cin>>s>>t;

    KMP kmp(s);

    cout<<kmp.Cnt(t);
    
    return 0;
}
