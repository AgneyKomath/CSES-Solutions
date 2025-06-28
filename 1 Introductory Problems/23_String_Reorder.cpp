#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int freq[26]{};
    for(char c:s) freq[c-'A']++;

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i<26; i++){
        if(freq[i]) pq.emplace(freq[i], i);
    }

    pair<int, int> prev = {0, -1};

    string res;
    while(!pq.empty()){
        auto [f, i] = pq.top();
        pq.pop();
        res.push_back(i + 'A');
        if(prev.first) pq.emplace(prev);
        prev = {f - 1, i};
    }

    if(prev.first != 0) cout<<-1;
    else cout<<res;
    
    return 0;
}
