#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int c[26];
    int w = 0;
    Node(){
        memset(c, -1, sizeof(c));
    }
};
 
vector<Node> trie;
 
void add(string &s){
    int curr = 0;
    for(char c:s){
        if(trie[curr].c[c-'a']==-1){
            trie[curr].c[c-'a'] = trie.size();
            trie.push_back(Node());
        }
        curr = trie[curr].c[c-'a'];
    }
    trie[curr].w ++;
}
 
const int mod = 1e9+7;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin>>s;
 
    int k;
    cin>>k;
 
    trie.push_back(Node());
 
    for(int i = 0; i<k; i++){
        string s;
        cin>>s;
        reverse(s.begin(), s.end());
        add(s);
    }
 
    int n = s.size();
 
    vector<int> dp(n+1, 0);
    dp[0] = 1;
 
    for(int i = 0; i<n; i++){
        int curr = 0;
        for(int j = i; j>=0; j--){
            if(trie[curr].c[s[j]-'a']==-1) break;
            curr = trie[curr].c[s[j]-'a'];
            dp[i+1] = (dp[i+1] + 1ll * trie[curr].w * dp[j]) % mod;
        }
    }
 
    cout<<dp[n];
    
    return 0;
}