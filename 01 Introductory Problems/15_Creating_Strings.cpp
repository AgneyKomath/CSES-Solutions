#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // std :: next_permutation
    string s;
    cin>>s;
    sort(s.begin(), s.end());

    vector<string> res;
    do{
        res.push_back(s);
    }
    while(next_permutation(s.begin(), s.end()));

    cout<<res.size()<<'\n';
    for(auto &i : res) cout<<i<<'\n';

    // // Backtracking
    // string s;
    // cin>>s;

    // int n = s.size();
    
    // int freq[26]{};
    // for(char c : s) freq[c - 'a']++;

    // vector<string> res;
    
    // auto f = [&](string &curr, auto && f){
    //     if(curr.size() == n){
    //         res.push_back(curr);
    //         return;
    //     }
    //     for(int i = 0; i < 26; i++){
    //         if(freq[i] == 0) continue;
    //         curr.push_back(i + 'a');
    //         freq[i]--;
    //         f(curr, f);
    //         freq[i]++;
    //         curr.pop_back();
    //     }
    // };
    
    // string curr;
    // f(curr, f);
    // cout<<res.size()<<'\n';
    // for(auto &i : res) cout<<i<<'\n';


    return 0;
}
