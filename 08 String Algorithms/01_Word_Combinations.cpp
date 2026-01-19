#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct Node{
    int child[26]{};
    bool w;
    Node(){
        memset(child, -1, sizeof(child));
        w = false;
    }
};

vector<Node> trie{Node()};

void addWord(string &s){
    int curr = 0;
    for(char c : s){
        int id = c - 'a';
        if(trie[curr].child[id] == -1){
            trie[curr].child[id] = trie.size();
            trie.push_back(Node());
        }
        curr = trie[curr].child[id];
    }
    trie[curr].w = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int n = s.size();

    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        string s;
        cin>>s;
        reverse(s.begin(), s.end());
        addWord(s);
    }

    vector<int> dp(n + 1);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        dp[i + 1] = 0;
        int curr = 0;
        for(int j = i; j >= 0; j--){
            int id = s[j] - 'a';
            if(trie[curr].child[id] == -1) break;
            curr = trie[curr].child[id];
            if(trie[curr].w){
                dp[i + 1] = (dp[i + 1] + dp[j]) % mod;
            }
        }
    }

    cout<<dp[n];

    return 0;
}
